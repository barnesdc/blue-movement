import binarytree
from binarytree import Node, build


#Creates a mirror of the tree
def mirror():
    #Pass in any values to create a tree
    values = [7, 3, 2, 6, 9, 1, 5, 8]
    if len(values)==1:
        print(values)
    elif len(values)==0:
        print("None")
    else:
        tree1=build(values)

        for i in range(len(tree1)):
            try:
                temp=tree1[i].left
                tree1[i].left=tree1[i].right
                tree1[i].right=temp
            except:
                print("no index")

        print(tree1)





#By alternating, we're able to go down the path where the leaf is
def make_branches(leaf,branches,branchess):

    for num in range(len(tree1)):
        if leaves[leaf] in tree1[num].left:
            #adds to branch
            branches.append(tree1[num].left)
            #checks if we're done with this branch
            if tree1[num].left==leaves[leaf]:
                branchess.append(branches)
                branches=[]
                break
        elif leaves[leaf] in tree1[num].right:
            branches.append(tree1[num].right)
            if tree1[num].right==leaves[leaf]:
                branchess.append(branches)
                branches=[]
                break

#This runs the code that recursively creates root to leaf branches
#Pass in any values you'd like
values = [7, 3, 2, 6, 9, 1, 5, 8]
if len(values)==1:
    print(values)
elif len(values)==0:
    print("None")
else:
    tree1=build(values)
    branchess=[]
    branch=list(tree1)
    leaves=tree1.leaves
    for leaf in range(len(leaves)):
        branches=[tree1[0]]
        make_branches(leaf,branches,branchess)
    print(branchess)


#MUST RUN BRANCH CREATION FUNCTION FIRST
#finds max difference between node and differences
def max_diff(branchess):
    branchess.extend((list(tree1),list(tree1.left),list(tree1.right)))

    newBranch=[]
    newBranches=[]
    #This is to get rid of the new lines and help us retrieve the numeric representation of the nodes
    for branch in branchess:
        branch=str(branch).strip('\n')
        for i in list(branch):
            if i.isnumeric():
                newBranch.append(int(i))
        newBranches.append(newBranch)
        newBranch=[]

    print(newBranches)
    maxDiff=0

    #this is to compare the differences between each node and it's decendants
    for branchDiff in newBranches:
        
        if maxDiff<(max(branchDiff)-min(branchDiff)):
                maxDiff=(max(branchDiff)-min(branchDiff))
    print(maxDiff)