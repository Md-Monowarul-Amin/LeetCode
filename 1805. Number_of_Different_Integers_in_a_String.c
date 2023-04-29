#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void insert_int_arr(int* arr, int size) {
    arr = realloc(arr, (size+1) * sizeof(arr[0]));
}


void generate_hash(char* num, int arr_global[]){
    int n = strlen(num);
    int ans = 0;
    //int power = n-1;
    int mod_value = 193013;
    double power = (double) (n - 1);
    for(int i=0; i <n; i++){
        int a = (int)num[i] - 48;

        //printf("%d", a);
        ans += ((int) pow(10.0, 3.0) * a) % mod_value;
        power -= 1;
    }
    ans = ans % mod_value;
    arr_global[ans] = 1;
    printf("NUM %s, ans %d\n", num, ans);

}

int numDifferentIntegers(char * word){
    int arr_global[100000] = {0};
    for(int i=0; i< 1000; i++){
        arr_global[i] = 0;
    }
    char* arr_chr;
    int arr_chr_size = 1;
    int arr_chr_ind = 0;
    int word_size = sizeof(word) / sizeof(word[0]);
    arr_chr = (char*)malloc((1 * sizeof(char)) / sizeof(char)); //It's a string

    for(int i=0; i< strlen(word); i++){ 
        if(48 <= (int)word[i] && (int)word[i]<= 57){
            // printf("Ascii %d", (int)word[i]);
            arr_chr[arr_chr_ind] = word[i];
            arr_chr_ind += 1;
            arr_chr_size +=1;
            arr_chr = realloc(arr_chr, arr_chr_size * sizeof(char));
        }
        else{

            int num = atoi(arr_chr);
            if(num != 0){
                generate_hash(arr_chr, arr_global);
            }

            free(arr_chr);
            arr_chr = (char*)malloc(1* sizeof(char));
            arr_chr_size = 1; 
            arr_chr_ind = 0;
        }

        printf("\n");
    }
    //printf("arr_chr %s\n", arr_chr);
    if (arr_chr != ""){
        generate_hash(arr_chr, arr_global);

    }

    int cnt = 0;
    for(int i=0; i< 100000; i++){
        if (arr_global[i] == 1){
            printf("i= %d ", i);
            cnt += 1;
        }

    } 
    return cnt;
}

int main(){
    char word[] = {"hha12354545bc34d8ef34"};
    int ans = numDifferentIntegers(word);
    printf("%d\n", ans);
}