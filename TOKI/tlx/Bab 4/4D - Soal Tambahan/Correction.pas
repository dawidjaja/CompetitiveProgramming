var
	msk,i,lgt,beda,min,nilai,j:longint;
	kata,temp:ansistring;
	cek,pnjg:array[0..3500] of longint;
	list:array[0..3500] of ansistring;
begin
	readln(msk);
	for i:=1 to msk do
		begin
		readln(list[i]);
		pnjg[i]:=length(list[i]);
		cek[i]:=0;
		end;
	readln(kata);
	lgt:=length(kata);
	for i:=1 to lgt do
		begin
		min:=999999;
		nilai:=ord(kata[i]);
		for j:=1 to msk do
			begin
			if pnjg[j]>=i then
				begin
				beda:=ord(list[j][i]);
				beda:=nilai-beda;
				beda:=abs(beda);
				if beda>13 then
					begin
					beda:=26-beda;
					end;
				cek[j]:=cek[j]+beda;
				if cek[j]<min then
					begin
					min:=cek[j];
					temp:=copy(list[j],1,i);
					end;
				end;	
			end;
		writeln(temp);
		end;
end.