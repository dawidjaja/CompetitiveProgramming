var
	i,temp,j,hsl:longint;
	msk,soal:string;
begin
readln(msk);
readln(soal);
hsl:=length(msk);
	for i:=0 to (length(soal)-length(msk)) do
		begin
		temp:=0;
		for j:=1 to length(msk) do
			begin
			if msk[j]=soal[i+j] then
				begin
				end
			else
				begin
				temp:=temp+1;
				end;
			end;
		if temp<hsl then
			begin
			hsl:=temp;
			end;
		end;
	writeln(hsl);
end.