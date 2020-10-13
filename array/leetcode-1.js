// var twoSum = function(nums, target) {
//   //   var res = [];
//   //   search(nums, 0, 2, target, res);
//   //   return res;
//   dict = {};
//   for (i in nums) {
//     if (dict[target - nums[i]]) return [i, dict[target - nums[i]]];
//     else dict[nums[i]] = i;
//   }
// };
function search(arr, index, k, n, res) {
  if (k > arr.length - index) return false;
  if (k == 0 && n == 0) return true;
  if (index >= arr.length) return false;
  res.push(arr[index]);
  for (let i = index+1; i < arr.length; i++) {
    if (search(arr, i + 1, k - 1, n - arr[i], res)) return true;
  }
  res.pop();
  return false;
}
arr = [1, 3, 5, 0, 2];
res = [];
console.log(search(arr, 0, 3, 4, res));
console.log(res);
