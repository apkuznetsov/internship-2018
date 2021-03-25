using System;

namespace task6
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }

    public void FillWithArray(double[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
            Insert(arr[i]);
    }

    public void Insert(double data, BinaryTree node, BinaryTree parent)  // добавление значения в узел дерева
    {
        if (node.Data == null || node.Data == data)
        {
            node.Data = data;
            node.Parent = parent;
            return;
        }
        if (node.Data > data)
        {
            if (node.Left == null)
                node.Left = new BinaryTree();
            Insert(data, node.Left, node);
        }
        else
        {
            if (node.Right == null)
                node.Right = new BinaryTree();
            Insert(data, node.Right, node);
        }

        public void Insert(double data, BinaryTree node, BinaryTree parent)  // добавление значения в узел дерева
        {
            if (Data == null || node.Data == data)
            {
                node.Data = data;
                node.Parent = parent;
                return;
            }
            if (node.Data > data)
            {
                if (node.Left == null)
                    node.Left = new BinaryTree();
                Insert(data, node.Left, node);
            }
            else
            {
                if (node.Right == null)
                    node.Right = new BinaryTree();
                Insert(data, node.Right, node);
            }
        }

        public void SwapLeftAndRight(BinaryTree node)
        {
            if (node != null)
            {
                BinaryTree tempNode = node.Left;
                node.Left = node.Right;
                node.Right = tempNode;

                SwapLeftAndRight(node.Left);
                SwapLeftAndRight(node.Right);
            }
        }

        public void RemoveLeafs(BinaryTree node)
        {
            if (node != null)
            {
                if (node.Left == null && node.Right == null)
                {
                    if (node.Parent.Left == node)
                        node.Parent.Left = null;
                    else
                        node.Parent.Right = null;

                    node = null;
                    return;
                }
                RemoveLeafs(node.Left);
                RemoveLeafs(node.Right);
            }
        }

        public void AddLeafToEachLeafAccordingToParityOfItsData(BinaryTree node)
        {
            if (node != null)
            {
                if (node.Left == null && node.Right == null)
                {
                    BinaryTree newNode = new BinaryTree { Data = node.Data };

                    if (node.Data % 2 == 0)
                        node.Right = newNode;
                    else
                        node.Left = newNode;

                    return;
                }
                AddLeafToEachLeafAccordingToParityOfItsData(node.Left);
                AddLeafToEachLeafAccordingToParityOfItsData(node.Right);
            }
        }

    }
