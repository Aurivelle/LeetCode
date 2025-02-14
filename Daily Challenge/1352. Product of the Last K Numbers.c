typedef struct 
{
    int* products;
    int* nums;
    int size;
    int capacity;
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() 
{
    ProductOfNumbers* product = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    product->size = 0;
    product->capacity = 2;
    product->products = (int*)malloc(sizeof(int) * 2);
    product->nums = (int*)malloc(sizeof(int) * 2);
    return product;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) 
{
    if(obj->size == obj->capacity )
    {
        obj->capacity *= 2;
        obj->products = (int*)realloc(obj->products, sizeof(int) * obj->capacity);
        obj->nums = (int*)realloc(obj->nums, sizeof(int) * obj->capacity);

    }
    
    obj->nums[obj->size] = num;
    if(num == 0)
    {
        for(int i = 0; i < obj->size; i++)
        {
            obj->products[i] = 0;
        }
        obj->products[obj->size] = 0;
    }
    else if(obj->size == 0 || obj->products[obj->size - 1] == 0)
    {
        obj->products[obj->size] = num;
    }
    else 
    {
        obj->products[obj->size] = obj->products[obj->size - 1] * num;
    }
    obj->size++;

}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) 
{
    if(obj->products[obj->size - k] == 0)
    {
        return 0;
    }

    int all = obj->products[obj->size - 1];
    int divide = obj->products[obj->size - k];
    int ans = all / divide * obj->nums[obj->size - k];
    return ans;
}

void productOfNumbersFree(ProductOfNumbers* obj) 
{
    free(obj->products);
    free(obj);  
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/
