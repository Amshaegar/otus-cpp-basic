#include <gtest/gtest.h>

#include "List.hpp"

namespace containers {

TEST(list, zero_size_at_start) {
    // Arrange
    List list = List<int>();

    int expected_size = 0;

    // Act
    int actual_size = list.size();

    // Assert
    EXPECT_EQ(expected_size, actual_size);
}

TEST(list, insert_front) {
    // Arrange
    List list = List<int>();

    int expected_size = 1;
    int expected_value = 42;

    // Act
    list.insert(0,expected_value);

    // Assert
    EXPECT_EQ(expected_size, list.size());
    EXPECT_EQ(expected_value, list[0]);
}

TEST(list, insert_middle) {
    // Arrange
    List list = List<int>();
    
    int insert_pos = 1;
    int expected_size = 3;
    int expected_value = 2;

    list.push_back(1);
    list.push_back(3);

    // Act
    list.insert(insert_pos,expected_value);

    // Assert
    EXPECT_EQ(expected_size, list.size());
    EXPECT_EQ(expected_value, list[insert_pos]);
}

TEST(list, insert_back) {
    // Arrange
    List list = List<int>();
    
    int expected_size = 1;
    int expected_value = 42;

    // Act
    list.push_back(expected_value);

    // Assert
    EXPECT_EQ(expected_size, list.size());
    EXPECT_EQ(expected_value, list[0]);
}

TEST(list, erase_front) {
    // Arrange
    List list = List<int>();

    int expected_size = 2;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Act
    list.erase(0);

    // Assert
    EXPECT_EQ(expected_size, list.size());
    EXPECT_EQ(2, list[0]);
    EXPECT_EQ(3, list[1]);
}

TEST(list, erase_middle) {
    // Arrange
    List list = List<int>();

    int expected_size = 2;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Act
    list.erase(1);

    // Assert
    EXPECT_EQ(expected_size, list.size());
    EXPECT_EQ(1, list[0]);
    EXPECT_EQ(3, list[1]);
}

TEST(list, erase_back) {
    // Arrange
    List list = List<int>();

    int expected_size = 2;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Act
    list.erase(2);

    // Assert
    EXPECT_EQ(expected_size, list.size());
    EXPECT_EQ(1, list[0]);
    EXPECT_EQ(2, list[1]);
}

} // containers