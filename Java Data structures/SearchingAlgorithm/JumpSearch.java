public class JumpSearch {
    public static int jumpSearch(int[] array, int target) {
        int n = array.length;
        int step = (int) Math.sqrt(n); // Calculate block size

        int prev = 0;
        // Jump to the next block until we find a block where `target` could exist
        while (array[Math.min(step, n) - 1] < target) {
            prev = step;
            step += (int) Math.sqrt(n);
            if (prev >= n) {
                return -1; // Target is not present in the array
            }
        }

        // Perform linear search within the block
        for (int i = prev; i < Math.min(step, n); i++) {
            if (array[i] == target) {
                return i;
            }
        }
        return -1; // Target is not present
    }

    public static void main(String[] args) {
        int[] array = {1, 3, 5, 7, 9, 11, 13, 15, 17};
        int target = 15;

        int result = jumpSearch(array, target);
        if (result == -1) {
            System.out.println("Element not found in the array.");
        } else {
            System.out.println("Element found at index: " + result);
        }
    }
}
