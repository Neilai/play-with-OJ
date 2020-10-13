var findMedianSortedArrays = function(nums1, nums2) {
  let arr = nums1.concat(nums2).sort((a, b) => a - b);
  let mid = parseInt(arr.length / 2);
  console.log(mid);
  if (arr.length % 2) return arr[mid];
  else return (arr[mid] + arr[mid - 1]) / 2;
};
