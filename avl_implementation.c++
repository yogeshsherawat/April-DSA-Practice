package com.company;


import sun.awt.image.ImageWatched;

import java.io.*;
import java.util.*;

class Node{
    int data,height;
    Node left,right;

    Node(int data){
        this.data = data;
        height=1;
        left = null;
        right  = null;
    }

}

public class Main {
    static Node rightRotate(Node y){
        Node x = y.left;
        Node T2 = x.right;
        x.right = y;
        y.left = T2;
        // height update
        y.height = Math.max(getHeight(y.left),getHeight(y.right))+1;
        x.height = Math.max(getHeight(x.left),getHeight(x.right))+1;
        return x;
    }
    static Node leftRotate(Node y){
        Node x = y.right;
        Node T2 = x.left;
        x.left = y;
        y.right = T2;
        // height updates
        y.height = Math.max(getHeight(y.left),getHeight(y.right))+1;
        x.height = Math.max(getHeight(x.left),getHeight(x.right))+1;

        return x;
    }

    static Node insert(Node node,int data){
        if(node==null)
            return new Node(data);
        if(data<node.data)
            node.left =  insert(node.left,data);
        else if(data>node.data)
            node.right = insert(node.right,data);
        else
            return node;
        node.height = Math.max(node.left.height,node.right.height)+1;
        int balance = getBalance(node);

        return node;
    }

    private static int getBalance(Node node) {
        if(node==null)
            return 0;
        return getHeight(node.left)-getHeight(node.right);
    }

    private static int getHeight(Node n) {
        if(n==null)
            return 0;
        return n.height;
    }

    static Node delete(Node node,int key){
        if(node==null)
            return node;
        if(node.data>key)
            node.left = delete(node.left,key);
        else if(node.data<key)
            node.right = delete(node.right,key);
        else{
            if(node.left==null)
                return node.right;
            else if(node.right==null)
                return node.left;
            node.data = inorderSuccessor(node.right);
            node.right = delete(node.right,key);
        }
        return node;
    }

    private static int inorderSuccessor(Node node) {
        if(node.left==null)
            return node.data;
        return inorderSuccessor(node.left);
    }

    static void inorder(Node node){
        if(node==null)
            return;
        inorder(node.left);
        System.out.print(node.data+" ");
        inorder(node.right);
    }
    static void bfs(Node node){
        Queue<Node> q= new LinkedList<>();
        q.add(node);
        while(!q.isEmpty()){
            Node n = q.poll();
            System.out.print(n.data+" ");
            if(n.left!=null)
                q.add(n.left);
            if(n.right!=null)
                q.add(n.right);
        }
    }

    public static void main(String[] args) throws IOException {

        Node root = new Node(3);
        root.left = new Node(1);
        root.left.right = new Node(2);
        root.right = new Node(4);
        root.right.right = new Node(5);
        inorder(root);
        System.out.println();
        bfs(root);

        delete(root,2);
        System.out.println();
        System.out.println("After Deletion:");
        bfs(root);





    }

}