//Viridiana Jimenez Diaz

public static void difference(Node info){

if (into == NULL){
	return info;
}

if (info.left == NULL && info.right == NULL){
	return info.data;
}
int number_max = Math.max(difference(info.left), difference(info.right));
int number_min = Math.min(difference(info.left), difference(info.right));

	int subtract = number_max -  number_min;

return subtract;


}



public static void way(Node nodo){

if (nodo == NULL){

	return ‘empty’;

}

if (nodo.right== NULL && nodo.left == NULL){

	for(int I=0 ; i<path; I++){
System.out.println(path[I]+”->”);
	else{

way(root.left);
way(root.right);

}
}

public static void three_mirror(Node nodo){

if (nodo == NULL){

return nodo;

}

Node l = three_mirror(nodo.left);
Nodo r = three_mirror(nodo.right);

swap(l, r);
return nodo;
}

}
