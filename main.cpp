#include <algorithm>
#include <atomic>
#include <iostream>
#include <limits>
#include <mutex>
#include <thread>
#include <vector>

#include "CRC32.hpp"
#include "IO.hpp"

std::atomic_bool found = false;
std::vector<char> answer;
std::mutex answerMutex;

/// @brief Переписывает последние 4 байта значением value
void replaceLastFourBytes(std::vector<char> &data, uint32_t value) {
  std::copy_n(reinterpret_cast<const char *>(&value), 4, data.end() - 4);
}

void calc(std::vector<char> data,
          const size_t batchBegin,
          const size_t batchEnd,
          const uint32_t originalCrc32){
  for (size_t i = batchBegin; i < batchEnd; ++i) {
    if (found) {
        return;
    }

    // Заменяем последние четыре байта на значение i
    replaceLastFourBytes(data, (uint32_t)i);
    // Вычисляем CRC32 текущего вектора result
    auto currentCrc32 = crc32(data.data(), data.size());

    if (currentCrc32 == originalCrc32) {
      found = true;
      std::lock_guard<std::mutex> guard(answerMutex);
      answer = data;
      return;
    }
  }
}

/**
 * @brief Формирует новый вектор с тем же CRC32, добавляя в конец оригинального
 * строку injection и дополнительные 4 байта
 * @details При формировании нового вектора последние 4 байта не несут полезной
 * нагрузки и подбираются таким образом, чтобы CRC32 нового и оригинального
 * вектора совпадали
 * @param original оригинальный вектор
 * @param injection произвольная строка, которая будет добавлена после данных
 * оригинального вектора
 * @return новый вектор
 */
std::vector<char> hack(const std::vector<char> &original,
                       const std::string &injection) {
  const uint32_t originalCrc32 = crc32(original.data(), original.size());

  std::vector<char> result(original.size() + injection.size() + 4);
  auto it = std::copy(original.begin(), original.end(), result.begin());
  std::copy(injection.begin(), injection.end(), it);

  /*
   * Внимание: код ниже крайне не оптимален.
   * В качестве доп. задания устраните избыточные вычисления
   */
  const size_t maxVal = std::numeric_limits<uint32_t>::max();

  unsigned int t = std::thread::hardware_concurrency();
  if (t == 0) {
    t=1;
  }

  std::cout << "Calculate in " << t << " concurrent threads." << std::endl;
  size_t batch_size = maxVal / t;
  std::cout << "Batch size: " << batch_size << std::endl;
  std::cout << "Max value: " << maxVal << std::endl;

  std::vector<std::thread> threads;
  for(size_t i = 0; i < t ; ++i) {
    size_t batchBegin = i*batch_size;
    size_t batchEnd = (i == t - 1) ? maxVal : batchBegin + batch_size;
    std:: cout << "Batch begin: " << batchBegin << std::endl;
    std:: cout << "Batch end: " << batchEnd << std::endl;
    threads.emplace_back(std::thread(calc,
                                     result,
                                     batchBegin,
                                     batchEnd,
                                     originalCrc32));
  }

  for(unsigned int i = 0; i < t ; ++i) {
    threads.at(i).join();
  }

  if (!found) {
    throw std::logic_error("Can't hack");
  }

  std::cout << "Success\n";

  return answer;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Call with two args: " << argv[0]
              << " <input file> <output file>\n";
    return 1;
  }

  try {
    const std::vector<char> data = readFromFile(argv[1]);
    const std::vector<char> badData = hack(data, "He-he-he");
    writeToFile(argv[2], badData);
  } catch (std::exception &ex) {
    std::cerr << ex.what() << '\n';
    return 2;
  }
  return 0;
}
