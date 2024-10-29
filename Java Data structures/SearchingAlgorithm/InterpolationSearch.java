public class InterpolationSearch {
    public static int interpolationSearch(int[] array, int target) {
        int low = 0;
        int high = array.length - 1;

        while (low <= high && target >= array[low] && target <= array[high]) {
            // Estimate the position using the interpolation formula
            int pos = low + ((target - array[low]) * (high - low) / (array[high] - array[low]));

            // If target is found
            if (array[pos] == target) {
                return pos;
            }
            // If target is larger, it is in the right subarray
            if (array[pos] < target) {
                low = pos + 1;
            }
            // If target is smaller, it is in the left subarray
            else {
                high = pos - 1;
            }
        }
        return -1; // Target not found
    }

    public static void main(String[] args) {
        int[] array = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24};
        int target = 18;

        int result = interpolationSearch(array, target);
        if (result == -1) {
            System.out.println("Element not found in the array.");
        } else {
            System.out.println("Element found at index: " + result);
        }
    }
}
