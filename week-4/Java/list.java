public static void reversed (Node head){



Node letter = head;

While(letter != NULL){

letter.data = function_reverseme(letter.data);
Letter = letter.next;
}
return head;

}

public static string function_reverseme( String str){

String reversed = “”;
for (int i<0; I<str.length; I++){

reversed += str.charAt(I);

}
return reversed;

}
