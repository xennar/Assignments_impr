#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 20
/*Prototypes are made*/
void prompt_for_input(char str[]);
void check_for_palindrome(char str[]);
int is_palindrome_iter(char str[], int str_len);
int is_palindrome_rec(char str[], int str_len);
int palindrome_rec(char str[], char *sp, char *ep);
void print_result(char str[], int iter_is, int rec_is);

/*Main function is initialized, space for the word-string is made in the heap, input is called for, and then the function-caller is called*/
int main() {
    char* str = (char*) malloc(MAX_LENGTH *sizeof(char));
    prompt_for_input(str);
    check_for_palindrome(str);
    return 0;
}
/*Input is prompted*/
void prompt_for_input(char str[]){
    printf("Hello, Please input your word so we can check if it is a palindrome. Please note that capital letters don't work:\n");
    scanf("%s", str);
}
/*All functions are called in order, and the memory in the heap is freed*/
void check_for_palindrome(char str[]){
    int str_len = strlen(str), iter_is, rec_is;
    iter_is = is_palindrome_iter(str, str_len);
    rec_is = is_palindrome_rec(str, str_len);
    print_result(str, iter_is, rec_is);
    free(str);
}

/*The iterative function is made, using for to make a reverse string.*/
int is_palindrome_iter(char str[], int str_len){
    int result;
    char* str_iter = (char*) malloc(MAX_LENGTH *sizeof(char));
    for(int h = 0; h < str_len; h++){
        str_iter[h] = str[str_len - h - 1];
    }
    str_iter[str_len] = '\0';
    result = strcmpi(str_iter, str);
    free(str_iter);
    return result;
}
/*The called function which starts the recursive solution*/
int is_palindrome_rec(char str[], int str_len){
    char *sp = str, *ep = &str[str_len - 1];
    return palindrome_rec(str, sp, ep);
}
/*The recursive function is made, checks if not palindrome, then continues checking til word is done*/
int palindrome_rec(char str[], char *sp, char *ep) {
    int answer = 0;
    if(*sp != *ep)
        answer = 1;
    else if(sp < ep)
        answer = palindrome_rec(str, sp + 1, ep - 1);
    return answer;
}
/*The result of two functions are printed. If either method messes up, the answer changes*/
void print_result(char str[], int iter_is, int rec_is){
    if(iter_is == 0 && rec_is == 0) /*0 is used for true, because the strcmp in the iterative function returns 0 if strings are the same*/
        printf("The word '%s' is a palindrome.\n", str);
    else
        printf("The word '%s' is not a palindrome.\n", str);
}