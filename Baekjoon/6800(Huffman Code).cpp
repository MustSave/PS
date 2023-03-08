#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// typedef struct node
// {
//     char c;
//     node* left = NULL;
//     node* right = NULL;
// } node;

// int main()
// {
//     int N;
//     char c;
//     char code[500];

//     struct node *root = new node;
//     root->left = NULL;
//     root->right = NULL;

//     scanf("%d", &N);

//     for (int i = 0; i < N; i++)
//     {
//         fflush(stdin);
//         scanf("%c %s", &c, code);
//         node* tmp = root;
//         for (int j = 0; code[j] != '\0'; j++)
//         {
//             bool left = code[j] == '0';
//             if (left)
//             {
//                 if (tmp->left == NULL)
//                 {
//                     struct node *n = new node;
//                     n->c = c;
//                     n->left = NULL;
//                     n->right = NULL;
//                     tmp->left = n;
//                 }
//                 tmp = tmp->left;
//             }
//             else
//             {
//                 if (tmp->right == NULL)
//                 {
//                     struct node *n = new node;
//                     n->c = c;
//                     n->left = NULL;
//                     n->right = NULL;
//                     tmp->right = n;
//                 }
//                 tmp = tmp->right;
//             }
//         }
//     }

//     scanf("%s", code);

//     node* tmp = root;
//     for (int i = 0; code[i] != '\0'; i++)
//     {
//         tmp = code[i] == '0' ? tmp->left : tmp->right;

//         if (tmp->left == NULL && tmp->right == NULL)
//         {
//             printf("%c", tmp->c);
//             tmp = root;
//         }
//     }

//     return 0;
// }


#include <map>

int main()
{
    int N;
    char c;
    char code[500];

    map<string, char> dic;
    map<string, char>::iterator iter;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        fflush(stdin);
        string str;
        // scanf("%c %s", &c, code);
        cin >> c >> str;
        dic.insert({str, c});
    }

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            iter = dic.find(s.substr(i, j-i+1));
            if (iter != dic.end())
            {
                printf("%c", iter->second);
                i = j;
                break;
            }
        }
    }
}