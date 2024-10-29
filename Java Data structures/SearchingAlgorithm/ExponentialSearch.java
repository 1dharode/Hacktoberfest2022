import java.util.Arrays;

public class ExponentialSearch {
    // Exponential search function
    public static int exponentialSearch(int[] array, int target) {
        if (array[0] == target) {
            return 0;
        }

        int i = 1;
        while (i < array.length && array[i] <= target) {
            i *= 2;
        }

        // Binary search within the found range
        return Arrays.binarySearch(array, i / 2, Math.min(i, array.length), target);
    }

    public static void main(String[] args) {
        int[] array = {3, 5, 7, 9, 10, 13, 15, 18, 20, 22, 25};
        int target = 18;

        int result = exponentialSearch(array, target);
        if (result < 0) {
            System.out.println("Element not found in the array.");
        } else {
            System.out.println("Element found at index: " + result);
        }
    }
}
