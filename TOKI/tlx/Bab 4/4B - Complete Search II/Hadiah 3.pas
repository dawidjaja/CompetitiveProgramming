var
	msk,hsl,n,ctr,j,temp,i:longint;
	list:array[0..100] of longint;
begin
readln(msk);
n:=1;
while msk<>0 do
	begin
	list[n]:=msk mod 3;
	msk:=msk div 3;
	n:=n+1;
	end;
ctr:=0;
for i:=1 to n do
	begin
	if list[i]=1 then
		begin
		ctr:=ctr+1;
		end;
	if list[i]=2 then
		begin
		ctr:=ctr+2;
		end;
	end;
writeln(ctr);
temp:=0;
for i:=1 to n do
	begin
	if temp=0 then
		begin
		if list[i]=1 then
			begin
			hsl:=1;
			for j:=2 to i do
				begin
				hsl:=hsl*3;
				end;
			write(hsl);
			temp:=temp+1;
			end;
		if list[i]=2 then
			begin
			hsl:=1;
			for j:=2 to i do
				begin
				hsl:=hsl*3;
				end;	
			write(hsl,' ',hsl);
			temp:=temp+1;	
			end;
		end
	else
		begin
		if list[i]=1 then
			begin
			hsl:=1;
			for j:=2 to i do
				begin
				hsl:=hsl*3;
				end;
			write(' ',hsl);
			temp:=temp+1;
			end;
		if list[i]=2 then
			begin
			hsl:=1;
			for j:=2 to i do
				begin
				hsl:=hsl*3;
				end;		
			write(' ',hsl,' ',hsl);
			temp:=temp+1;	
			end;
		end;
	end;
	writeln;
end.