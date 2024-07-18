/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct
{
    int * ret_arr;
    int ret_arr_size;
}ret_val;

ret_val traversal(struct TreeNode * root, int distance, int * count)
{
    if(root)
    {
        ret_val l_subtree = traversal(root->left, distance, count);
        ret_val r_subtree = traversal(root->right, distance, count);

        //Leaf Node
        if(!root->left && !root->right)
        {
            ret_val ret;
            int * tmp_arr = (int *)malloc(sizeof(int) * 1);
            tmp_arr[0] = 1;
            ret.ret_arr = tmp_arr;
            ret.ret_arr_size = 1;
            return ret;
        }

        //Traverse all the distance from leftsubtree
        int * first_arr = l_subtree.ret_arr;
        int first_arr_size = l_subtree.ret_arr_size;

        int * second_arr = r_subtree.ret_arr;
        int second_arr_size = r_subtree.ret_arr_size;

        int i=0;
        int j=0;

        for(i=0; i<first_arr_size; i++)
        {
            for(j=0; j<second_arr_size; j++)
            {
                if(first_arr[i] + second_arr[j] <= distance)
                {
                    *count += 1;
                }
            }
        }

        //Increment 1 to both arrays
        for(i=0; i<first_arr_size; i++)
        {   
            first_arr[i] += 1;
        }

        for(j=0; j<second_arr_size; j++)
        {
            second_arr[j] += 1;
        }


        //Combine the 1st and 2nd into one array
        ret_val ret;
        int * tmp_arr = (int *)malloc(sizeof(int) * (first_arr_size + second_arr_size));;
        for(i=0; i<first_arr_size; i++)
        {
            tmp_arr[i] = first_arr[i];
        }

        for(i=0; i<second_arr_size; i++)
        {
            tmp_arr[first_arr_size + i] = second_arr[i];
        }
        ret.ret_arr = tmp_arr;
        ret.ret_arr_size = first_arr_size + second_arr_size;
        return ret;
    }

    ret_val ret;
    ret.ret_arr = NULL;
    ret.ret_arr_size = 0;
    return ret;
}

int countPairs(struct TreeNode* root, int distance) 
{
    int count = 0;

    traversal(root, distance, &count);    
    return count;
}