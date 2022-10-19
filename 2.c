#include <stdio.h>
#include <stdlib.h>

struct games
{
	char title[50];
	float rating;
};
typedef struct games Game;



int main()
{
    int n;
    scanf("%i", &n);
    Game g[n];


    for(int i=0; i<n; i++){
        scanf("%[^:]", g[i].title);
        int count;
        scanf(":%i", &count);

        float sum = 0;
        for(int k=0; k<count; k++){
            int q;
            scanf("%i", &q);
            sum+=q;
        }
        g[i].rating = sum/count;
    }
//        сортировка
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n - 1 - i; j++){
//                условие сортировки
                if (g[j].rating < g[j + 1].rating)
                    {
                    Game temp = g[j];
                    g[j] = g[j + 1];
                    g[j + 1] = temp;
                    }
            }
        }
        for (int i = 0; i < n; i++){
            printf("%s: %.3lf", g[i].title, g[i].rating);
        }


}
