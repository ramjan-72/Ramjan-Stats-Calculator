#include <stdio.h>
#include <math.h>

#define MAX 100

// Function prototypes
void basic_operations();
void statistics();
float mean(float data[], int n);
float median(float data[], int n);
float mode(float data[], int n);
float assumed_mean(float data[], int n, float assumed);
float harmonic_mean(float data[], int n);
float geometric_mean(float data[], int n);
float variance(float data[], int n);
float skewness(float data[], int n);
float kurtosis(float data[], int n);
void sort(float data[], int n);

int main() {
    int choice;
    while (1) {
        printf("\n---- RAMJAN CALCULATOR ----\n");
        printf("1. Basic Operations (+, -, *, /)\n");
        printf("2. Statistical Functions\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: basic_operations(); break;
            case 2: statistics(); break;
            case 3: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

void basic_operations() {
    float a, b;
    char op;
    printf("Enter expression (e.g., 5 + 3): ");
    scanf("%f %c %f", &a, &op, &b);
    
    switch (op) {
        case '+': printf("Result = %.2f\n", a + b); break;
        case '-': printf("Result = %.2f\n", a - b); break;
        case '*': printf("Result = %.2f\n", a * b); break;
        case '/':
            if (b != 0) printf("Result = %.2f\n", a / b);
            else printf("Division by zero!\n");
            break;
        default: printf("Invalid operator\n");
    }
}

void statistics() {
    float data[MAX], assumed;
    int n, i;
    int choice;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the data:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &data[i]);
    }

    printf("\n--- Statistical Functions ---\n");
    printf("1. Mean\n");
    printf("2. Median\n");
    printf("3. Mode\n");
    printf("4. Assumed Mean\n");
    printf("5. Harmonic Mean\n");
    printf("6. Geometric Mean\n");
    printf("7. Variance\n");
    printf("8. Skewness\n");
    printf("9. Kurtosis\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: printf("Mean = %.2f\n", mean(data, n)); break;
        case 2: printf("Median = %.2f\n", median(data, n)); break;
        case 3: printf("Mode = %.2f\n", mode(data, n)); break;
        case 4: 
            printf("Enter assumed mean: ");
            scanf("%f", &assumed);
            printf("Assumed Mean = %.2f\n", assumed_mean(data, n, assumed));
            break;
        case 5: printf("Harmonic Mean = %.2f\n", harmonic_mean(data, n)); break;
        case 6: printf("Geometric Mean = %.2f\n", geometric_mean(data, n)); break;
        case 7: printf("Variance = %.2f\n", variance(data, n)); break;
        case 8: printf("Skewness = %.2f\n", skewness(data, n)); break;
        case 9: printf("Kurtosis = %.2f\n", kurtosis(data, n)); break;
        default: printf("Invalid choice\n");
    }
}

float mean(float data[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) sum += data[i];
    return sum / n;
}

void sort(float data[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (data[i] > data[j]) {
                float temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

float median(float data[], int n) {
    sort(data, n);
    if (n % 2 == 0)												
        return (data[n/2 - 1] + data[n/2]) / 2.0;
    else
        return data[n/2];
}

float mode(float data[], int n) {
    int maxCount = 0;
    float mode = data[0];
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (data[j] == data[i])
                count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mode = data[i];
        }
    }
    return mode;
}

float assumed_mean(float data[], int n, float assumed) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += data[i] - assumed;
    }
    return assumed + (total / n);
}

float harmonic_mean(float data[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] == 0) return 0;
        sum += 1.0 / data[i];
    }
    return n / sum;
}

float geometric_mean(float data[], int n) {
    float product = 1;
    for (int i = 0; i < n; i++) {
        if (data[i] <= 0) return 0;
        product *= data[i];
    }
    return pow(product, 1.0 / n);
}

float variance(float data[], int n) {
    float m = mean(data, n);
    float var = 0;
    for (int i = 0; i < n; i++) {
        var += (data[i] - m) * (data[i] - m);
    }
    return var / n;
}

float skewness(float data[], int n) {
    float m = mean(data, n);
    float sd = sqrt(variance(data, n));
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow((data[i] - m) / sd, 3);
    }
    return sum / n;
}

float kurtosis(float data[], int n) {
    float m = mean(data, n);
    float sd = sqrt(variance(data, n));
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow((data[i] - m) / sd, 3);
    }
    return sum / n - 3	;  
}
