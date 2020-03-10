
/*
Find The Duplicates
Given two sorted arrays arr1 and arr2 of passport numbers, implement a function findDuplicates
that returns an array of all passport numbers that are both in arr1 and arr2. Note that the
output array should be sorted in an ascending order.

Let N and M be the lengths of arr1 and arr2, respectively. Solve for two cases and analyze the
time & space complexities of your solutions: M ≈ N - the array lengths are approximately the
same M ≫ N - arr2 is much bigger than arr1.

Example:

input:  arr1 = [1, 2, 3, 5, 6, 7]
arr2 = [3, 6, 7, 8, 20]

output: [3, 6, 7] # since only these three values are both in arr1 and arr2

input:
arr1 = [1,1,1,2,3,5,5,5,6,7]
arr2 = [5,6,6 7,8,20]
*/

/*
 dups = [5, 6, 6, 7]  // 0(nlogn)
*/
//BS 1 = true;

#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findDuplicates(std::vector<int> &nums1, std::vector<int> &nums2);
bool binarySearch(int n, std::vector<int> nums);
std::vector<int> findDuplicates_BS(std::vector<int> &nums1, std::vector<int> &nums2);
int main()
{
    std::vector<int> nums1 {1, 1, 1, 2, 3, 5, 5, 5, 6, 7};
    std::vector<int> nums2 {1, 1, 3, 6, 6, 7, 8, 20};
    std::vector<int> dups = findDuplicates_BS(nums1, nums2);
    for(int n : dups){
      std::cout << n << ", ";
    }
    std::cout << std::endl;
    return 0;
}

std::vector<int> findDuplicates(std::vector<int> &nums1, std::vector<int> &nums2)
{
  std::unordered_set<int> mySet;
  std::vector<int> duplicates;
  for(int n : nums1){
    mySet.insert(n);
  }
  for(int n : nums2){
    if(mySet.find(n) != mySet.end()){
      duplicates.push_back(n);
    }
  }
  return duplicates;
}

bool binarySearch(int n, std::vector<int> nums)
{
  int low = 0, high = nums.size() - 1;
  while(low <= high){
    int mid = low + (high-low)/2;
    if(n == nums[mid]){
      return true;
    }
    else if(n > nums[mid]){
      low = mid+1;
    }
    else{
      high = mid-1;
    }
  }
  return false;
}

/*

target = 8
nums = [1, 1, 1, 2, 3, 5, 5, 5, 6, 7]
        0  1  2  3  4  5  6  7  8  9
size = 10
low = 0
high = 9
mid = 9-0=9/2=4
nums[mid] = 3
8 == 3
8 > 3 si
  low = 4 + 1
*/

std::vector<int> findDuplicates_BS(std::vector<int> &nums1, std::vector<int> &nums2)
{
  std::vector<int> duplicates;
  if(nums1.size() > nums2.size()){
    std::vector<int> temp = nums2;
    nums2 = nums1;
    nums1 = temp;
    //return findDuplicates_BS(nums2, nums1);
  }
  for(int n : nums1){
    if(binarySearch(n, nums2)){
      duplicates.push_back(n);
    }
  }
  return duplicates;
}
