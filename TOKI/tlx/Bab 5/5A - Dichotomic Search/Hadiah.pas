var
	biner,bin:array[0..30] of byte;
	list:array[0..30] of int64;
	a,b,c,n,x,num,temp,hsl:int64;
	i,dummy:longint;
begin
	readln(a,b,c,n);
	if n=1 then
		begin
		writeln('1');
		exit;
		end;
	if a=1 then
		begin
		writeln('1');
		exit;
		end;		
	if a=0 then
		begin
		writeln('1');
		exit;
		end;
	if b=0 then
		begin
		writeln('2');
		exit;
		end;
	if c=0 then
		begin
		hsl:=((a mod n)+1);
		writeln(hsl);
		exit;
		end;
	x:=1;
	while b>0 do
		begin
		biner[x]:=(b mod 2);
		b:=b div 2;
		x:=x+1;
		end;
	for i:=1 to x-1 do
		begin
		bin[i]:=biner[x-i];
		end;
	temp:=(a mod n);
	x:=x-1;
	for dummy:=1 to c do
		begin
		list[1]:=(temp mod n)*(temp mod n);
		list[1]:=list[1] mod n;
		if bin[i]=1 then
			begin
			list[1]:=list[1]*temp;
			list[1]:=list[1] mod n;
			end;
		for i:=2 to x do
			begin
			num:=list[i-1]*list[i-1];
			num:=num mod n;
			if bin[i]=1 then
				begin
				num:=num*temp;
				end;
			num:=num mod n;
			list[i]:=num;
			end;
		temp:=list[x] mod n;
		end;
	temp:=temp+1;
	writeln(temp);
end.