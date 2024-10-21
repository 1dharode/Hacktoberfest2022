import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;

public class ListUtils {

    /**
     * Removes duplicates from a given list while maintaining the order of elements.
     * @param list The input list from which duplicates need to be removed.
     * @param <T> The type of elements in the list.
     * @return A new list without duplicate elements.
     */
    public static <T> List<T> removeDuplicates(List<T> list) {
        // Using LinkedHashSet to maintain insertion order and remove duplicates
        return new ArrayList<>(new LinkedHashSet<>(list));
    }

    public static void main(String[] args) {
        // Example usage
        List<String> items = new ArrayList<>();
        items.add("apple");
        items.add("banana");
        items.add("apple");
        items.add("orange");
        items.add("banana");

        System.out.println("Original List: " + items);
        List<String> uniqueItems = removeDuplicates(items);
        System.out.println("List without duplicates: " + uniqueItems);
    }
}
