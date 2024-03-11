bool isPalindrome(int x) {
    if (x<0)
        return false;
    int rev = 0;
    int orginal =x;
    while(x>0) {
        int remainder = x%10;
        rev = rev*10+remainder;
        x = x/10;
    }
    if(rev==orginal)
        return true;
    else
        return false;
}
