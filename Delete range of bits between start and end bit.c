//write a function to delete a range of bits given the start bit and the end bit.
int main()
{
    int val = 100;
    int tmp;
    int n = (1 << (sizeof(val) * 8 - 1)) - 1; //get a mask of all bits set
    int l = 2, r = 5;
    printf("%b ", val);
    printf("%b ", n);
    tmp = ((1<<l)-1) ^ ((1<<r)-1); //get the bits set between l and r
    printf("%b ", tmp);
    tmp = n ^ tmp; //get all the bits unset beween l and r  in the mask
    printf("%b ", tmp); 
    val = val & tmp; 
    printf("%b ", val);
     //printf(" num is %b \n ", n);
    //printf("result is %b", unsetBitsInGivenRange(n, l, r));
    return 0;
}
