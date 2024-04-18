#include <stdio.h>
#include <string.h>
#include<math.h>
#include<stdlib.h>
void Remove_AllOccurrence(char *str, const char ch, int index){
    int k;
    while (str[index] != '\0'){
        if (str[index] == ch){
            for (k = index; str[k] != '\0'; k++){
                str[k] = str[k + 1];
            }
        }
        else{
            index++;
        }
    }
}

void Remove_AllDuplicates(char *str){
    int i;
    for (i = 0; i < strlen(str); i++){
        Remove_AllOccurrence(str, str[i], i + 1);
    }
}

int main(){
    int key_len;
    printf("Enter Length of key\n");
    scanf("%d", &key_len);

    char key[key_len];
    printf("Enter Key\n");
    scanf("%s", key);
    Remove_AllDuplicates(key);
    key_len = strlen(key);
    char alphabet[25] = "abcdefghiklmnopqrstuvwxyz";
    int alpha_len = 25;
    int i, j, l;
    char key_mat[5][5];
    int k = 0;
    int alpha_k = 0;
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            if (k < key_len){
                key_mat[i][j] = key[k];
                for (l = 0; l < alpha_len; l++){
                    if (alphabet[l] == key[k]){
                        while (l < alpha_len - 1){
                            alphabet[l] = alphabet[l + 1];
                            l++;
                        }
                        alpha_len--;
                        break;
                    }
                }
                k++;
            }
            else{
                key_mat[i][j] = alphabet[alpha_k];
                alpha_k++;
            }
        }
    }

// for (i = 0; i < 5; i++)
// {
// for (j = 0; j < 5; j++)
// {
// printf("%c ", key_mat[i][j]);
// }
// printf("\n");
// }
    char text[100];
    printf("Enter Text to Encrypt\n");
    scanf("%s",text);
    int text_len=strlen(text);
    j=text_len;
    for(i=0;i<text_len;i+=2){
        if(text[i]==text[i+1]){
            while(j>i){
                text[j+1]=text[j];
                j--;
            }
        text[i+1]='x';
        }
    }
    if(strlen(text)%2!=0){
        text[strlen(text)+1]='x';
    }
    for(i=0;i<strlen(text);i+=2){
        int row1,col1;
        int row2,col2;
    char a=text[i];
    char b=text[i+1];
    for(j=0;j<5;j++){
        for(k=0;k<5;k++){
            if(key_mat[j][k]==a){
                row1=j;
                col1=k;
            }
            if(key_mat[j][k]==b){
                row2=j;
                col2=k;
            }
        }
    }
    if(row1==row2){
        text[i]=key_mat[row1][(col1+1)%5];
        text[i+1]=key_mat[row2][(col2+1)%5];
    }
else if(col1==col2){
text[i]=key_mat[(row1+1)%5][col1];
text[i+1]=key_mat[(row2+1)%5][col2];
}
else{
text[i]=key_mat[row1][col2];
text[i+1]=key_mat[row2][col1];
}
}
printf("Encrypted Text using playfair is %s\n",text);
int len_text = strlen(text);
int depth;
printf("Enter depth of rail fence: ");
scanf("%d", &depth);
int rows = depth;
int columns = ceil(len_text / (float) depth);
char railfence[rows][columns];
k = 0;
for (i = 0; i < columns; i++) {
for (j = 0; j < rows; j++) {
if (k < len_text) {
railfence[j][i] = text[k];
k++;
} else {
railfence[j][i] = '\0';
}
}
}
char cypher_text[50];
k = 0;
for (i = 0; i < rows; i++) {
for (j = 0; j < columns; j++) {
if (railfence[i][j] != '\0') {
cypher_text[k] = railfence[i][j];
k++;
}
}
}
cypher_text[k] = '\0';
printf("Rail fence cipher: %s\n", cypher_text);
k=0;
for(i=0;i<rows;i++){
for(j=0;j<columns;j++){
if(k<text_len){
railfence[i][j]=cypher_text[k];
k++;
}
else{
railfence[i][j]='\0';
}
}
}
k = 0;
for (i = 0; i < columns; i++) {
for (j = 0; j < rows; j++) {
if (railfence[j][i]!='\0') {
text[k]=railfence[j][i];
k++;
}
}
}
int row1,row2,col1,col2;
printf("Decryption of railfence is %s\n",text);
for(i = 0; i < text_len; i += 2) {
char a = text[i];
char b = text[i + 1];
for(j = 0; j < 5; j++) {
for(k = 0; k < 5; k++) {
if(key_mat[j][k] == a) {
row1 = j;
col1 = k;
}
if(key_mat[j][k] == b) {
row2 = j;
col2 = k;
}
}
}
if(row1 == row2) {
text[i] = key_mat[row1][(col1 - 1 + 5) % 5];
text[i + 1] = key_mat[row2][(col2 - 1 + 5) % 5];
}
else if(col1 == col2) {
text[i] = key_mat[(row1 - 1 + 5) % 5][col1];
text[i + 1] = key_mat[(row2 - 1 + 5) % 5][col2];
}
else {
text[i] = key_mat[row1][col2];
text[i + 1] = key_mat[row2][col1];
}
}
// Remove padding 'x' if added
if(text[text_len - 1] == 'x') {
text[text_len - 1] = '\0';
}
printf("Decrypted text using playfair is %s\n",text);
return 0;
}
