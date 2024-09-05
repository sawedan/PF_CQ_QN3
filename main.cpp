#include <iostream> // Include the standard input-output stream library

// Function to sum all integers between 'first' and 'last' (inclusive)
int sum_from_to(int first, int last) {
    int sum = 0; // Initialize the sum to 0
    // Loop through all integers from 'first' to 'last', inclusive
    for (int i = first; i <= last; ++i) {
        sum += i; // Add the current integer 'i' to the sum
    }
    return sum; // Return the calculated sum
}

// Function to find the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    // Loop until 'b' becomes 0
    while (b != 0) {
        int temp = b; // Store the current value of 'b' in a temporary variable
        b = a % b; // Update 'b' to be the remainder of 'a' divided by 'b'
        a = temp; // Update 'a' to the old value of 'b'
    }
    return a; // When 'b' is 0, 'a' contains the GCD
}

// Function to reduce a fraction by dividing the numerator and denominator by their GCD
int reduce(int& num, int& denom) {
    // Check if either the numerator or denominator is zero or negative, which is invalid for reduction
    if (num <= 0 || denom <= 0) {
        return 0; // Return 0 to indicate failure to reduce the fraction
    }
    int divisor = gcd(num, denom); // Find the GCD of the numerator and denominator
    num /= divisor; // Divide the numerator by the GCD to simplify the fraction
    denom /= divisor; // Divide the denominator by the GCD to simplify the fraction
    return 1; // Return 1 to indicate successful reduction
}

// Main function to test the above functions
int main() {
    // Declare variables to store user inputs for the sum_from_to function
    int first, last;
    std::cout << "Enter the first number for sum: "; // Prompt the user for the first number of the range
    std::cin >> first; // Read the first number
    std::cout << "Enter the last number for sum: "; // Prompt the user for the last number of the range
    std::cin >> last; // Read the last number

    // Output the sum of numbers from 'first' to 'last'
    std::cout << "Sum from " << first << " to " << last << ": " << sum_from_to(first, last) << std::endl;

    // Declare variables to store the numerator and denominator of a fraction
    int num, denom;
    std::cout << "Enter the numerator of the fraction: "; // Prompt the user for the numerator
    std::cin >> num; // Read the numerator
    std::cout << "Enter the denominator of the fraction: "; // Prompt the user for the denominator
    std::cin >> denom; // Read the denominator

    // Display the original fraction
    std::cout << "Original fraction: " << num << "/" << denom << std::endl;
    // Attempt to reduce the fraction and check if successful
    if (reduce(num, denom)) {
        std::cout << "Reduced fraction: " << num << "/" << denom << std::endl; // Output the reduced fraction
    } else {
        std::cout << "Failed to reduce the fraction." << std::endl; // Output a failure message if reduction was not possible
    }
    return 0; // Indicate that the program ended successfully
}
