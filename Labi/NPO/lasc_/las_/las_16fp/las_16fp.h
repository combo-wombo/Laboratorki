#ifndef las_16FP
#define las_16FP

#define las_SIZE 100
#include <stdbool.h>
struct las_data
{	
	char las_material_name[20];
	int las_price;
	int las_count;
	int las_cost;
};

void las_10fv(struct las_data* las_value);

#endif
