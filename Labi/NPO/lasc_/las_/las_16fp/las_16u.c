#include <stdio.h>
#include <stdbool.h>
#include "las_16fp.h"

void las_10fv(struct las_data* las_value)
{
	las_value->las_cost = las_value->las_count * las_value->las_price;
}
