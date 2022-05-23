#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>



int findLRU(int array[], int n){
    int i, minimum = array[0], position = 0;
    
    for(i = 1; i < n; ++i){
        if(array[i] < minimum){
            minimum = array[i];
            position = i;
        }
    }
    return position;
}


int findOptimal(int array[], int n){
    int i, maximum = array[0], position = 0;
    
    for(i = 1; i < n; ++i){
        if(array[i] > maximum){
            maximum = array[i];
            position = i;
        }
    }
    return position;
}



int main(int argc, const char * argv[]) {
    int number_frames = 0,temp=0,x=0,switcher=0,no_pages=0;         //scan variables
    int calc =0;
    int indicator;
    int size =0,count =0,places=0;          //Variables for FIFO
    int page[5500];
    scanf("%d",&number_frames);
    int frames[number_frames];
    char replacement_type[100];
    scanf("%s",replacement_type);
    while (x==0) {
        scanf("%d",&temp);
        if (temp != -1) {
            page[no_pages] = temp;
            ++no_pages;
        }
        else
            x=1;
    }
    
    if (switcher == strcmp(replacement_type, "FIFO")) {
        
        printf("Replacement Policy = FIFO\n");
        printf("-------------------------------------\n");
        printf("Page   ");
        printf("Content of Frames\n");
        printf("----   ");
        printf("-----------------\n");
        
        for (int j=0; j<number_frames; j++) {
            frames[j]=-1;
        }
        
        for (int i=0 ; i<no_pages; i++) {
            indicator =1;
            for (int m =0; m<number_frames; m++) {
                if (page[i] == frames[m]) {
                    indicator =0;
                    printf("%02d     ",page[i]);
                }
            }
            if (indicator ==1)
            {
                frames[places] = page[i];
                calc = places + 1;
                places = calc % number_frames;
                printf("%02d",page[i]);
                
                size = size + 1;
                if (size > number_frames)
                {
                    printf(" F   ");
                    count = count +1;
                }
                else
                {
                    printf("     ");
                }
            }
            for(int f = 0;f < number_frames;f++)
            {
                if(frames[f] != -1){
                    
                    printf("%02d ",frames[f]);
                }
                
            }
            printf("\n");
            
        }
        printf("-------------------------------------\n");
        printf("Number of page faults = %d\n",count);
        printf("\n");
        
    }
    
    
    
    if (switcher == strcmp(replacement_type, "LRU")) {
        printf("Replacement Policy = LRU\n");
        printf("-------------------------------------\n");
        printf("Page   ");
        printf("Content of Frames\n");
        printf("----   ");
        printf("-----------------\n");
        int number_times[5500];
        int counter =0;
        for (int j=0; j<number_frames; j++) {
            frames[j]=-1;
            number_times[j]=0;
        }
        int size=0;
        for (int i=0 ; i<no_pages; i++) {
            indicator =1;
            for (int m =0; m<number_frames; m++) {
                if (page[i] == frames[m]) {
                    indicator =0;
                    counter++;
                    number_times[m]=counter;
                    printf("%02d     ",page[i]);
                }
            }
            if (indicator ==1)
            {
                printf("%02d",page[i]);
                if (size<number_frames) {
                    frames[places] = page[i];
                    size++;
                    counter++;
                    number_times[places]=counter;
                    places++;
                    printf("     ");
                    
                }
                else{
                    int pos = findLRU(number_times, number_frames);
                    frames[pos] = page[i];
                    counter++;
                    number_times[pos] = counter;
                    count = count +1;
                    printf(" F   ");
                    
                }
                
            }
            for(int fh = 0;fh < number_frames;fh++)
            {
                if(frames[fh] != -1){
                    printf("%02d ",frames[fh]);
                }
                
            }
            printf("\n");
            
        }
        printf("-------------------------------------\n");
        printf("Number of page faults = %d\n",count);
        printf("\n");
        
    }
    
    
    
    
    if (switcher == strcmp(replacement_type, "OPTIMAL")) {
        printf("Replacement Policy = OPTIMAL\n");
        printf("-------------------------------------\n");
        printf("Page   ");
        printf("Content of Frames\n");
        printf("----   ");
        printf("-----------------\n");
        
        int number_times[5000];
        int found =0;
        int pos=-1;
        for (int j=0; j<number_frames; j++) {
            frames[j]=-1;
        }
        int size=0;
        for (int i=0 ; i<no_pages; i++) {
            indicator =1;
            for (int m =0; m<number_frames; m++) {
                if (page[i] == frames[m]) {
                    indicator =0;
                    printf("%02d     ",page[i]);
                }
            }
            if (indicator ==1)
            {
                printf("%02d",page[i]);
                if (size<number_frames) {
                    frames[places] = page[i];
                    places++;
                    size++;
                    printf("     ");
                    
                }
                else{
                    for (int h=0; h<number_frames; h++) {
                        found =0;
                        for (int n=i+1; n<no_pages; n++) {
                            if (frames[h]==page[n]) {
                                number_times[h] = n;
                                found=1;
                                break;
                            }
                            else{
                                found =0;
                            }
                        }
                        if (found == 0) {
                            number_times[h] = no_pages;
                        }
                    }
                    pos = findOptimal(number_times, number_frames);
                    
                    frames[pos] = page[i];
                    count = count +1;
                    printf(" F   ");
                    
                }
                
            }
            for(int fh = 0;fh < number_frames;fh++)
            {
                if(frames[fh] != -1)
                    printf("%02d ",frames[fh]);
                
            }
            printf("\n");
            
        }
        
        printf("-------------------------------------\n");
        printf("Number of page faults = %d\n",count);
        printf("\n");
        
        
    }
    
    
    
    return 0;
}

