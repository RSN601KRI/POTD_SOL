// User function Template for Java

// arr[] : int input array of integers
// k : the quadruple sum required

class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(int[] arr, int k) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        Arrays.sort(arr);

        for (int i = 0; i < arr.length - 3; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) {
                continue; // Skip duplicate elements
            }
            for (int j = i + 1; j < arr.length - 2; j++) {
                if (j > i + 1 && arr[j] == arr[j - 1]) {
                    continue; // Skip duplicate elements
                }
                int left = j + 1;
                int right = arr.length - 1;

                while (left < right) {
                    int sum = arr[i] + arr[j] + arr[left] + arr[right];
                    if (sum == k) {
                        ArrayList<Integer> quadruplet = new ArrayList<>();
                        quadruplet.add(arr[i]);
                        quadruplet.add(arr[j]);
                        quadruplet.add(arr[left]);
                        quadruplet.add(arr[right]);
                        result.add(quadruplet);

                        while (left < right && arr[left] == arr[left + 1]) {
                            left++; // Skip duplicate elements
                        }
                        while (left < right && arr[right] == arr[right - 1]) {
                            right--; // Skip duplicate elements
                        }
                        left++;
                        right--;
                    } else if (sum < k) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
}
