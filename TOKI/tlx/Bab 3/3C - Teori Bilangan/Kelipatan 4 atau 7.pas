var
	list:array[0..10000000] of longint;
	msk,pat,juh,dl,hsl:int64;
	i:longint;
begin
	readln(msk);
	for i:=1 to msk do
		begin
		readln(list[i]);
		end;
	for i:=1 to msk do
		begin
			pat:=list[i] div 4;
			pat:=pat*(pat+1);
			pat:=pat div 2;
			juh:=list[i] div 7;
			juh:=juh*(juh+1);
			juh:=juh div 2;
			dl:=list[i] div 28;
			dl:=dl*(dl+1);
			dl:=dl div 2;
			hsl:=((pat*4)+(juh*7))-(dl*28);
			writeln(hsl);
		end;
end.