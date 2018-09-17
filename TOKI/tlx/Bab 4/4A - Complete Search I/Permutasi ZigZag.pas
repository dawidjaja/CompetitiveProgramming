var
	msk,i,cek:integer;
	tnd,isi:array[0..10] of integer;
procedure pzz(x:integer);
var
	n:integer;
begin
	if x=msk+1 then
		begin
		cek:=0;
		for n:=2 to msk-1 do
			begin
			if (((isi[n]>isi[n+1]) and (isi[n]>isi[n-1])) or ((isi[n]<isi[n+1]) and (isi[n]<isi[n-1]))) then
				begin
				end
			else
				begin
				cek:=1;
				end;
			end;
		if cek=0 then
			begin
			for n:=1 to msk-1 do
				begin
				write(isi[n]);
				end;
			writeln(isi[msk]);
			end;
		end
	else
		begin
		for n:=1 to msk do
			begin
			if tnd[n]=0 then
				begin
				tnd[n]:=1;
				isi[x]:=n;
				pzz(x+1);
				tnd[n]:=0;
				end;
			end;
		end;
end;
begin
	readln(msk);
	for i:=1 to msk do
		begin
		tnd[i]:=0;
		end;
		pzz(1);
end.