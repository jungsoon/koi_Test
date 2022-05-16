#include<stdio.h>

int main(){

    int n, m=0, m1=0, m2=0, m3=0;

    scanf("%d",&n);
    if(n<=500){

    int a[n]={0};

    for(int i=0;i<n;i++){

        scanf("%d",&a[i]);

    }

    int x,y,z; //x,y:国 z:国烹

    y=n-1; //国烹 国 国

    for(z=0;z<n-2;z++){

        for(x=z+1;x<n-1;x++){

            for(int i=z;i<x;i++){
                m1=0;
                m1+=a[i];
            }

            m1=m1*2;
            for(int i=x+1;i<y;i++){
                m1+=a[i];
            }

            if(m<m1){
                m=m1;
            }
        }

    }
    printf("*%d\n",m);

    x=0; //国 国 国烹

    for(z=2;z<n;z++){

        for(y=1;y<z;y++){

            m2=0;

            for(int i=y+1;i<z+1;i++){

                m2+=a[i];

            }

            m2=m2*2;

            for(int i=1;i<y;i++){

                m2+=a[i];

            }

            if(m<m2){

                m=m2;

            }

        }

    }
     printf("-%d\n",m);

    for(z=1;z<n-1;z++){ //国 国烹 国

        for(y=0;y<z;y++){

            for(x=z+1;x<n;x++){

                m3=0;

                for(int i=y+1;i<z+1;i++){

                    m3+=a[i];

                }

                for(int i=z;i<x;i++){

                    m3+=a[i];

                }

                if(m<m3){

                    m=m3;

                }

            }

        }

    }
    }

    printf("%d",m);

}

