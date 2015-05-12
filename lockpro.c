#include <stdio.h>

#define MIN 0
#define MAX 39
#define SIZE 10

void generate_numbers(int *numbers);
int adjust(int number);
int validate_range(int number);
int validate_second(int second, int third);
void print_first(int *first);
void print_second(int *second, int third);
void print_combinations(int *first, int *second, int third);

int main(int argc, char** argv) {
  int i, j, magic,
      first[SIZE] = {0},
      second[SIZE] = {0},
      third = -1;

  if (argc == 2) {
    sscanf(argv[1], "%2d", &third);
    if (third == 0 && argv[1][0] != '0')
      third = -1;
  }

  if (!validate_range(third)) {
    printf("Usage: ./lockpro THIRD\n");
    printf("THIRD should be between %d and %d.\n", MIN, MAX);
    return 1;
  }

  magic = third % 4;
  first[0] = magic;
  generate_numbers(first);

  if (magic < 2) second[0] = magic + 2;
  else second[0] = magic - 2;
  generate_numbers(second);

  print_first(first);
  print_second(second, third);
  print_combinations(first, second, third);

  return 0;
}

/**
 * Generate numbers, starting at numbers[i-1] and incrementing by 4.
 * @param[out]  numbers  the array to store the numbers
 */
void generate_numbers(int *numbers) {
  int i;
  for (i=1; i<SIZE; i++)
    numbers[i] = numbers[i-1] + 4;
}

/**
 * Adjust the number to within [0, MAX] using modulus.
 * @param[in]  number  the number to adjust
 * @return  the adjusted number
 */
int adjust(int number) {
  return number % (MAX + 1);
}

/**
 * Validate whether number is within [MIN, MAX].
 * @param[in]  number  the number to validate
 * @return  1 if valid, 0 if not
 */
int validate_range(int number) {
  return number >= MIN && number <= MAX;
}

/**
 * Check whether the second number is valid.
 *
 * The second number is valid if:
 *
 * 1. it is within [MIN, MAX]
 * 2. it is not within 2 of third (after adjustments)
 *
 * @param[in]  second  the number to validate
 * @param[in]  third  used as part of the validation
 * @return  1 if valid, 0 if not
 */
int validate_second(int second, int third) {
  return validate_range(second) &&
         second != adjust(third - 2) &&
         second != adjust(third + 2);
}

/**
 * Print the array of first numbers.
 * @param[in]  first  the array of first numbers
 */
void print_first(int *first) {
  printf("Possible first numbers:  ");
  int i;
  for (i=0; i<SIZE; i++) {
    if (validate_range(first[i]))
      printf("%-4d", first[i]);
  }
  printf("\n");
}

/**
 * Print the array of second numbers.
 * @param[in]  second  the array of second numbers
 * @param[in]  third  used to validate the second number when printing
 */
void print_second(int *second, int third) {
  printf("Possible second numbers: ");
  int i;
  for (i=0; i<SIZE; i++) {
    if (validate_second(second[i], third))
      printf("%-4d", second[i]);
  }
  printf("\n");
}

/**
 * Print all possible combinations.
 * @param[in]  first  the array of first numbers
 * @param[in]  second  the array of second numbers
 * @param[in]  third  the third number
 */
void print_combinations(int *first, int *second, int third) {
  printf("Possible combinations:\n");
  int i, j;
  for (i=0; i<SIZE; i++) {
    for (j=0; j<SIZE; j++) {
      if (validate_second(second[j], third))
        printf("(%d, %d, %d)\n", first[i], second[j], third);
    }
  }
}
