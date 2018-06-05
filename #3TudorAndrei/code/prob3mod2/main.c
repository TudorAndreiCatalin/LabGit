#include <stdio.h>
#include <stdlib.h>

struct task    //structuri
{
    int start;
    int finish;
    int duration;
} taskuri[20],taskAux;

void bubbleSort(struct task arr[], int n)
{
    int i, j;                                     //orodonare cu metoda bulelorr
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j].duration > arr[j+1].duration)
            {
                taskAux.start = arr[j].start;             //aux=x;
                taskAux.finish=arr[j].finish;
                taskAux.duration=arr[j].duration;

                arr[j].start = arr[j+1].start;              //x=y;
                arr[j].finish = arr[j+1].finish;
                arr[j].duration = arr[j+1].duration;

                arr[j+1].start= taskAux.start;              //y=aux;
                arr[j+1].finish= taskAux.finish;
                arr[j+1].duration= taskAux.duration;
            }
            else
                if(arr[j].duration == arr[j+1].duration)
                {
                    if(arr[j].start > arr[j+1].start)
                    {
                        taskAux.start = arr[j].start;             //aux=x;
                        taskAux.finish=arr[j].finish;
                        taskAux.duration=arr[j].duration;

                        arr[j].start = arr[j+1].start;              //x=y;
                        arr[j].finish = arr[j+1].finish;
                        arr[j].duration = arr[j+1].duration;

                        arr[j+1].start= taskAux.start;              //y=aux;
                        arr[j+1].finish= taskAux.finish;
                        arr[j+1].duration= taskAux.duration;

                    }

                }


}

int main()
{

    FILE *myFile;
    myFile = fopen("in.txt", "r");
    int numberArray[1000];
    int i,j;
    int n;
    int t;
    printf("time=");
    scanf("%d",&t);

    if (myFile == NULL)   // daca avem cv de citit
    {
        printf("Error Reading File\n");
        exit (0);
    }

    fscanf(myFile, "%d,", &numberArray[0]);
    n=numberArray[0];
    j=0;
    for (i = 1; i <= n*2; i++)                                   // scriere in fisier
    {
        fscanf(myFile, "%d,", &numberArray[i] );
        if(i%2!=0)
        {
            taskuri[j].start=numberArray[i];
        }
        if(i%2==0)
        {
            taskuri[j].finish=numberArray[i];
            j++;
        }
    }

    for (i = 0; i < n; i++)                    // cat dureaza un taskk
    {
        taskuri[i].duration=taskuri[i].finish-taskuri[i].start;
    }

    bubbleSort(taskuri,n);           // apelam functia bublesort ce ordoneaza in functie de durata si de start

    for (i = 0; i < n; i++)
    {
        printf("task_%d: start_%d, finish_%d , duration_%d\n\n", i,taskuri[i].start,taskuri[i].finish,taskuri[i].duration );
    }

    int k=1;
    int aux;
    aux=taskuri[0].finish;
            for(i=0;i<=n-2;i++){                //ordornareeeeeeeeeee
                for(j=i+1;j<=n-1;j++){
                if(aux<=taskuri[j].start)
                {
                    k=k+taskuri[j].duration;

                    aux=taskuri[j].finish;
                       i++;
                }
            }

}
printf("k=%d",k);
    fclose(myFile);

    return 0;
}
