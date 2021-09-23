#include <gtest/gtest.h>
#include <string>

#include "torch/csrc/lazy/core/hash.h"
#include "torch/csrc/lazy/core/int128.h"

namespace torch {
namespace lazy {

TEST(HashTest, Sanity) {
    // repeatable
    auto str_a = std::string("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut at suscipit purus.");
    hash_t hash_a = Hash(str_a);
    hash_t hash_a_2 = Hash(str_a);
    EXPECT_EQ(hash_a, hash_a_2);

    // sensitive
    std::string str_b = str_a;
    str_b.at(6) = 'I';
    hash_t hash_b = Hash(str_b);
    EXPECT_NE(hash_a, hash_b);
}

} // namespace lazy
} // namespace torch