//Nitis Jadipang 66070501020

// Dictionary

#include<stdio.h>
#include<string.h> //hint
#include<string.h>

typedef struct{
	char value[100];
	char key[100];
}dict;

int editdict(dict data[], int number,char check[], char value[]) {
    int changes = 0;

    for (int i = 0; i < number; i++) {
        if (strcmp(data[i].key, check) == 0) {
            strcpy(data[i].value, value);
            changes = 1;
        }
    }

    return changes;
}

void printdict(dict *dic, int size){ //for printing the output
	for(int i=0; i<size ; i++){
		printf("%s : %s\n",dic[i].key,dic[i].value);
	}
}

int main(){
	int size;
	scanf("%d",&size);
	dict dic[size]; //you can do this to declare structure in the array
    for (int i = 0; i < size; ++i) {
        scanf("%s %s", dic[i].key, dic[i].value);
    }
    char check[100];
    char value[100];
    scanf("%s %s", check, value);
    int binary = editdict(dic, size, check, value);
    if(binary == 0)
    {
        printf("No change\n");
    }
    printdict(dic, size);
}