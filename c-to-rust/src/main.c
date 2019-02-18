#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>



extern int32_t double_input(int32_t input);
extern uint32_t how_many_characters(const char *str);
extern char *theme_song_generate(uint8_t length);
extern void theme_song_free(char *);
extern uint32_t sum_of_even(const uint32_t *numbers, size_t length);
typedef struct {
  uint32_t x;
  uint32_t y;
} tuple_t;
extern tuple_t flip_things_around(tuple_t);


typedef struct zip_code_database zip_code_database_t;
extern zip_code_database_t *zip_code_database_new(void);
extern void zip_code_database_free(zip_code_database_t *);
extern void zip_code_database_populate(zip_code_database_t *);
extern uint32_t zip_code_database_population_of(const zip_code_database_t *, const char *zip);




typedef struct	s_vector {
	uint8_t			*values;
	uint8_t			size;
}				t_vector;


extern t_vector createLIst();
extern t_vector create_anotherLIst();

int main() {
	//Parse int
    int input = 4;
    int output = double_input(input);
    printf("%d * 2 = %d\n", input, output);

	//Parse String + return Int
	uint32_t count = how_many_characters("göes to élevên");
 	 printf("nbr character = %d\n", count);

	//Parse Int + return String
	char *song = theme_song_generate(5);
	printf("%s\n", song);
	theme_song_free(song);//return the ownership

	//Parse arrayInt +  return Int
	uint32_t numbers[] = {1, 2, 3, 4, 5, 6};
	size_t length = sizeof numbers / sizeof *numbers;
	uint32_t sum = sum_of_even(numbers, length);
	printf("sum %d\n", sum);

	// Parse Struct
	tuple_t initial = { .x = 10, .y = 20 };
	tuple_t result = flip_things_around(initial);
  	printf("tuple1 = (%" PRIu32 ",%" PRIu32 ")\n", result.x, result.y);
	tuple_t initial2 = { .x = 12, .y = 22 };
	tuple_t result2 = flip_things_around(initial2);
  	printf("tuple2 = (%" PRIu32 ",%" PRIu32 ")\n", result2.x, result2.y);
  	printf("tuple1 = (%" PRIu32 ",%" PRIu32 ")\n", result.x, result.y);

	zip_code_database_t *database = zip_code_database_new();
	zip_code_database_populate(database);
	uint32_t pop1 = zip_code_database_population_of(database, "90210");
	uint32_t pop2 = zip_code_database_population_of(database, "20500");
	zip_code_database_free(database);

	printf("%" PRId32 "\n", (int32_t)pop1 - (int32_t)pop2);


	t_vector vector = createLIst();
	int i;
	i = 0;
	while (i < vector.size) {
		printf("%d ", vector.values[i]);
		i++;
	}
	printf("\n");
	t_vector vector2 = create_anotherLIst();
	i = 0;
	while (i < vector2.size) {
		printf("%d ", vector2.values[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < vector.size) {
		printf("%d ", vector.values[i]);
		i++;
	}
	printf("\n");
    return 0;
}
