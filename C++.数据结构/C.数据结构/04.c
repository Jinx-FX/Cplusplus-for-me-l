#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char symbol;
    int weit;
}syml_weit;

typedef struct {
    int weight;
    int parent, lch, rch;
}HtNode,*hufftree;

int search_min_1(hufftree t, int i) {
    int s1;
    for(int j=1;j<i;j++) {
        if(t[j].parent==0) {
            s1 = j;
            break;
        }
    }
    for(int j=1;j<i;j++) {
        if(t[j].parent==0 && t[j].weight<t[s1].weight) {
            s1 = j;
        }
    }
    return s1;
}

int search_min_2(hufftree t, int i, int s1) {
    int s2;
    int num=0;
    for(int j=1;j<i;j++) {
        if(t[j].parent==0 && t[j].weight!=t[s1].weight) {
            s2 = j;
            break;
        }
    }
    for(int j=1;j<i;j++) {
        if(t[j].parent==0 && t[j].weight<t[s2].weight && t[j].weight>=t[s1].weight) {
            if(t[j].weight==t[s1].weight) {
                ++num;
                if(num>=2) {
                    s2 = j;
                    break;
                }
            }
            else
                s2 = j;
        }
    }
    return s2;
}

int main() {
    // 字符频度的统计
    syml_weit sw[94];
    int num=0;
    char line[1] = {0};
    FILE *file = fopen("02.txt", "r");
    if(!file)
        exit(1);
    while(1) {
        // 一个一个字符地读取
        if(EOF==fscanf(file, "%c", line))
            break;

        for (int j=0;j<1;j++) {
            if (num==0) {
                sw[0].symbol = line[0];
                sw[0].weit = 1;
                num++;
            }
            else {
                for (int n=0;n<num;n++) {
                    if (sw[n].symbol==line[j]) {
                        sw[n].weit++;
                        break;
                    }
                    if(sw[n].symbol!=line[j] && n==num-1) {
                        sw[num].symbol = line[j];
                        sw[num].weit = 1;
                        num++;
                        break;
                    }
                }
            }
        }
    }
    fclose(file);
    //字符统计显示
    for (int i=0;i<num;i++) {
        //printf("Num %d ASCII码", i+1);
        printf("\"%c\" : %3d个  ",sw[i].symbol,sw[i].weit);
        if(i%5==1)
            printf("\n");
    }
    printf("\n----------------------------------------------------------------------\n");
    // //排序
    // int k,t;
    // for(int i=0;i<num-1;i++) {
    //     k = i;
    //     for(int j=i+1;j<num;j++) {
    //         if(sw[j].weit<sw[k].weit)
    //             k = j;
    //     }
    //     if(sw[k].weit!=sw[i].weit) {
    //         t = sw[i].weit;
    //         sw[i].weit = sw[k].weit;
    //         sw[k].weit = t;
    //     }
    // }


    // hufftree
    int leafnode, totalnode;
    int add=0;
    leafnode = num;
    totalnode = 2 * leafnode - 1;
    hufftree htree;
    htree = (hufftree)malloc((totalnode + 1) * sizeof(HtNode));
    // 初始化
    htree[0].weight = 0;
    htree[0].parent = 0;
    htree[0].lch = 0;
    htree[0].rch = 0;
    for(int i=1;i<leafnode+1;i++) {
        htree[i].weight = sw[i-1].weit;
        htree[i].parent = 0;
        htree[i].lch = 0;
        htree[i].rch = 0;
        add += sw[i-1].weit;
    }
    for(int i=leafnode+1;i<=totalnode;i++) {
        htree[i].weight = 0;
        htree[i].parent = 0;
        htree[i].lch = 0;
        htree[i].rch = 0;
    }
    for(int i=leafnode+1;i<=totalnode;i++) {
        int s1=search_min_1(htree,i);
        int s2=search_min_2(htree,i,s1);

        //printf("%d s1:%3d s2:%3d\n",i-leafnode, s1, s2);

        htree[s1].parent = i;
        htree[s2].parent = i;
        htree[i].lch = s1;
        htree[i].rch = s2;
        htree[i].weight = htree[s1].weight + htree[s2].weight;
    }
    printf("\n");
    printf("\n根结点应该是: %d\n",add);
    printf("\n");
    for(int i=1;i<=totalnode;i++) {
        printf("%5d",htree[i].weight);
        if(i==leafnode)
            printf("\n----------------------------------------------------------------------\n");
        if(i%10 == 0)
            printf("\n");
    }
    printf("\n");
    return 0;
}



