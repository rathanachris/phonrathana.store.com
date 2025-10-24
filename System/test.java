public mainclass Apptest {

    // ការបង្កើត Method main ដែលជាចំណុចចូល (entry point) របស់កម្មវិធី
    public static void main(String[] args) {
        // បង្ហាញសារ សំរាប់តេស្ត
        System.out.println("Hello, Apptest!");

        // អ្នកអាចបន្ថែម code ផ្សេងៗនៅទីនេះ
        int result = addNumbers(5, 10);
        System.out.println("Result of addition: " + result);      
    }
    // Method ផ្ទាល់ខ្លួនសំរាប់បូកលេខ
    public static int addNumbers(int a, int b) {
        return a + b;
    }
}
