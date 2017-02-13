/*-------------------------------------------------------------------------------
  This file is part of gradient-forest.

  gradient-forest is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  gradient-forest is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with gradient-forest. If not, see <http://www.gnu.org/licenses/>.
 #-------------------------------------------------------------------------------*/

#include <map>
#include <unordered_set>
#include <fstream>
#include <random>

#include "catch.hpp"
#include "BootstrapSampler.h"

size_t absoluteDifference(size_t first, size_t second) {
  return first >= second ? first - second : second - first;
}

TEST_CASE("Draw without replacement 1", "[drawWithoutReplacement]") {
  std::vector<size_t> result;
  std::random_device random_device;
  std::map<size_t, uint> counts;

  SamplingOptions sampling_options(true, {});
  BootstrapSampler* bootstrap_sampler = new BootstrapSampler(
      random_device(), sampling_options);

  size_t max = 9;
  std::vector<size_t> skip = std::vector<size_t>({7});
  size_t num_samples = 4;
  size_t num_replicates = 10000;

  size_t expected_count = num_samples * num_replicates / max;

  for (size_t i = 0; i < num_replicates; ++i) {
    result.clear();
    bootstrap_sampler->drawWithoutReplacementSkip(result, max + 1, skip, num_samples);
    for (auto& idx : result) {
      ++counts[idx];
    }
  }

  // Check if counts are expected +- 5%
  for (auto& c : counts) {
    size_t difference = absoluteDifference(expected_count, c.second);
    REQUIRE(difference < expected_count * 0.05);
  }
  REQUIRE(0 == counts[skip[0]]);
}

TEST_CASE("Draw without replacement 2", "[drawWithoutReplacement]") {
  std::vector<size_t> result;
  std::random_device random_device;
  std::map<size_t, uint> counts;

  SamplingOptions sampling_options(true, {});
  BootstrapSampler* bootstrap_sampler = new BootstrapSampler(random_device(), sampling_options);

  size_t max = 9;
  std::vector<size_t> skip = std::vector<size_t>({0});
  size_t num_samples = 4;
  size_t num_replicates = 10000;

  size_t expected_count = num_samples * num_replicates / max;

  for (size_t i = 0; i < num_replicates; ++i) {
    result.clear();
    bootstrap_sampler->drawWithoutReplacementSkip(result, max + 1, skip, num_samples);
    for (auto& idx : result) {
      ++counts[idx];
    }
  }

  // Check if counts are expected +- 5%
  for (auto& c : counts) {
    size_t difference = absoluteDifference(expected_count, c.second);
    REQUIRE(difference < expected_count * 0.05);
  }
  REQUIRE(0 == counts[skip[0]]);
}

TEST_CASE("Draw without replacement 3", "[drawWithoutReplacement]") {
  std::vector<size_t> result;
  std::random_device random_device;
  std::map<size_t, uint> counts;

  SamplingOptions sampling_options(true, {});
  BootstrapSampler* bootstrap_sampler = new BootstrapSampler(random_device(), sampling_options);

  size_t max = 9;
  std::vector<size_t> skip = std::vector<size_t>({9});
  size_t num_samples = 4;
  size_t num_replicates = 10000;

  size_t expected_count = num_samples * num_replicates / max;

  for (size_t i = 0; i < num_replicates; ++i) {
    result.clear();
    bootstrap_sampler->drawWithoutReplacementSkip(result, max + 1, skip, num_samples);
    for (auto& idx : result) {
      ++counts[idx];
    }
  }

  // Check if counts are expected +- 5%
  for (auto& c : counts) {
    size_t difference = absoluteDifference(expected_count, c.second);
    REQUIRE(difference < expected_count * 0.05);
  }
  REQUIRE(0 == counts[skip[0]]);
}

TEST_CASE("Draw without replacement 4", "[drawWithoutReplacement]") {
  std::vector<size_t> result;
  std::random_device random_device;
  std::map<size_t, uint> counts;

  SamplingOptions sampling_options(true, {});
  BootstrapSampler* bootstrap_sampler = new BootstrapSampler(random_device(), sampling_options);
  
  size_t max = 1000;
  std::vector<size_t> skip = std::vector<size_t>({7});
  size_t num_samples = 50;
  size_t num_replicates = 100000;

  size_t expected_count = num_samples * num_replicates / max;

  for (size_t i = 0; i < num_replicates; ++i) {
    result.clear();
    bootstrap_sampler->drawWithoutReplacementSkip(result, max + 1, skip, num_samples);
    for (auto& idx : result) {
      ++counts[idx];
    }
  }

  // Check if counts are expected +- 10%
  for (auto& c : counts) {
    size_t difference = absoluteDifference(expected_count, c.second);
    REQUIRE(difference < expected_count * 0.10);
  }
  REQUIRE(0 == counts[skip[0]]);
}

TEST_CASE("Draw without replacement 5", "[drawWithoutReplacement]") {
  std::vector<size_t> result;
  std::random_device random_device;
  std::map<size_t, uint> counts;

  SamplingOptions sampling_options(true, {});
  BootstrapSampler* bootstrap_sampler = new BootstrapSampler(random_device(), sampling_options);

  size_t max = 1000;
  std::vector<size_t> skip = std::vector<size_t>({7});
  size_t num_samples = 500;
  size_t num_replicates = 10000;

  size_t expected_count = num_samples * num_replicates / max;

  for (size_t i = 0; i < num_replicates; ++i) {
    result.clear();
    bootstrap_sampler->drawWithoutReplacementSkip(result, max + 1, skip, num_samples);
    for (auto& idx : result) {
      ++counts[idx];
    }
  }

  // Check if counts are expected +- 5%
  for (auto& c : counts) {
    size_t difference = absoluteDifference(expected_count, c.second);
    REQUIRE(difference < expected_count * 0.05);
  }
  REQUIRE(0 == counts[skip[0]]);
}


TEST_CASE("Shuffle and split 1", "[shuffleAndSplit]") {
  std::random_device random_device;

  SamplingOptions sampling_options(true, {});
  BootstrapSampler* bootstrap_sampler = new BootstrapSampler(random_device(), sampling_options);

  std::vector<size_t> first_part;
  std::vector<size_t> second_part;

  bootstrap_sampler->shuffleAndSplit(first_part, second_part, 10, 3);

  REQUIRE(3 == first_part.size());
  REQUIRE(7 == second_part.size());
}

TEST_CASE("Shuffle and split 2", "[shuffleAndSplit]") {
  std::random_device random_device;

  SamplingOptions sampling_options(true, {});
  BootstrapSampler* bootstrap_sampler = new BootstrapSampler(random_device(), sampling_options);

  std::vector<size_t> first_part;
  std::vector<size_t> second_part;

  bootstrap_sampler->shuffleAndSplit(first_part, second_part, 100, 63);

  REQUIRE(63 == first_part.size());
  REQUIRE(37 == second_part.size());
}

TEST_CASE("Shuffle and split 3", "[shuffleAndSplit]") {
  std::random_device random_device;

  SamplingOptions sampling_options(true, {});
  BootstrapSampler* bootstrap_sampler = new BootstrapSampler(random_device(), sampling_options);

  std::vector<size_t> first_part;
  std::vector<size_t> second_part;

  bootstrap_sampler->shuffleAndSplit(first_part, second_part, 1, 1);

  REQUIRE(1 == first_part.size());
  REQUIRE(0 == second_part.size());
}

TEST_CASE("Shuffle and split 4", "[shuffleAndSplit]") {
  std::random_device random_device;

  SamplingOptions sampling_options(true, {});
  BootstrapSampler* bootstrap_sampler = new BootstrapSampler(random_device(), sampling_options);
  
  std::vector<size_t> first_part;
  std::vector<size_t> second_part;

  bootstrap_sampler->shuffleAndSplit(first_part, second_part, 3, 0);

  REQUIRE(0 == first_part.size());
  REQUIRE(3 == second_part.size());
}
