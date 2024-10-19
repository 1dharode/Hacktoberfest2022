import java.util.HashMap;

public class HashCodeExample {

    public static void main(String[] args) {
        // Creating objects
        Student student1 = new Student(1, "Alice");
        Student student2 = new Student(2, "Bob");
        Student student3 = new Student(1, "Alice");        
        // Creating a HashMap
        HashMap<Student, String> studentMap = new HashMap<>();       
        // Adding elements to the HashMap
        studentMap.put(student1, "A Grade");
        studentMap.put(student2, "B Grade");        
        // Retrieving elements from the HashMap
        System.out.println("Grade of student1: " + studentMap.get(student1)); 
        System.out.println("Grade of student2: " + studentMap.get(student2));        
        // Using student3 to retrieve a value
        System.out.println("Grade of student3: " + studentMap.get(student3)); 
    }
}
// Student class with overridden hashCode and equals methods
class Student {
    private int id;
    private String name;
    // Constructor
    public Student(int id, String name) {
        this.id = id;
        this.name = name;
    }
    // Override hashCode method
    @Override
    public int hashCode() {
        // Generate hashCode based on id and name
        int result = 17;
        result = 31 * result + id;
        result = 31 * result + (name != null ? name.hashCode() : 0);
        return result;
    }
    // Override equals method for the HashMap key comparison
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Student student = (Student) obj;
        if (id != student.id) return false;
        return name != null ? name.equals(student.name) : student.name == null;
    }
}


//Output:
// Grade of student1: A Grade
// Grade of student2: B Grade
// Grade of student3: A Grade
