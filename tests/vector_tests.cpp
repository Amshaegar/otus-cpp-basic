#include <gtest/gtest.h>

#include "Vector.hpp"

namespace containers {

TEST(vector, zero_size_at_start) {
    // Arrange
    Vector vector = Vector<int>();

    int expected_size = 0;

    // Act
    int actual_size = vector.size();

    // Assert
    EXPECT_EQ(expected_size, actual_size);
}

TEST(vector, insert_front) {
    // Arrange
    Vector vector = Vector<int>();

    int expected_size = 1;
    int expected_value = 42;

    // Act
    vector.insert(0,expected_value);

    // Assert
    EXPECT_EQ(expected_size, vector.size());
    EXPECT_EQ(expected_value, vector[0]);
}

TEST(vector, insert_middle) {
    // Arrange
    Vector vector = Vector<int>();
    
    int insert_pos = 1;
    int expected_size = 3;
    int expected_value = 2;

    vector.push_back(1);
    vector.push_back(3);

    // Act
    vector.insert(insert_pos,expected_value);

    // Assert
    EXPECT_EQ(expected_size, vector.size());
    EXPECT_EQ(expected_value, vector[insert_pos]);
}

TEST(vector, insert_back) {
    // Arrange
    Vector vector = Vector<int>();
    
    int expected_size = 1;
    int expected_value = 42;

    // Act
    vector.push_back(expected_value);

    // Assert
    EXPECT_EQ(expected_size, vector.size());
    EXPECT_EQ(expected_value, vector[0]);
}

TEST(vector, erase_front) {
    // Arrange
    Vector vector = Vector<int>();

    int expected_size = 2;

    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);

    // Act
    vector.erase(0);

    // Assert
    EXPECT_EQ(expected_size, vector.size());
    EXPECT_EQ(2, vector[0]);
    EXPECT_EQ(3, vector[1]);
}

TEST(vector, erase_middle) {
    // Arrange
    Vector vector = Vector<int>();

    int expected_size = 2;

    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);

    // Act
    vector.erase(1);

    // Assert
    EXPECT_EQ(expected_size, vector.size());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(3, vector[1]);
}

TEST(vector, erase_back) {
    // Arrange
    Vector vector = Vector<int>();

    int expected_size = 2;

    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);

    // Act
    vector.erase(2);

    // Assert
    EXPECT_EQ(expected_size, vector.size());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
}

} // containers