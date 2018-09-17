var
	list,ctr:array[-10000..10000] of longint;
	msk,dummy,pb,pd,x,y,n,temp,cek,i:longint;
	a,b,c:char;
	cmd,zzz:string;
begin
	readln(msk);
	n:=0;
	pd:=0;
	pb:=1;
	cek:=1;
	for dummy:=1 to msk do
		begin
		read(a,b,c);
		cmd:=(a+b+c);
		if cmd='add' then
			begin
			readln(x,y);
			n:=n+y;
			list[pb]:=x;
			ctr[pb]:=y;
			pb:=pb+cek;
			writeln(n);
			end;
		if cmd='del' then
			begin
			readln(y);
			n:=n-y;
			writeln(list[pd+cek]);
			while y>0 do
				begin
				if ctr[pd+cek]<=y then
					begin
					y:=y-ctr[pd+cek];
					pd:=pd+cek;
					end
				else
					begin
					ctr[pd+cek]:=ctr[pd+cek]-y;
					y:=0;
					end;
				end;
			end;
		if cmd='rev' then
			begin
			readln(zzz);
			temp:=pb;
			pb:=pd;
			pd:=temp;
			if cek=1 then
				begin
				cek:=-1;
				end
			else
				begin
				cek:=1;
				end;
			end;
		{if cek=1 then
			begin
			for i:=pd+1 to pb-1 do
				begin
				writeln(list[i],' ',ctr[i]);
				end;
			end;
		if cek=-1 then
			begin
			for i:=pd-1 downto pb+1 do
				begin
				writeln(list[i],' ',ctr[i]);
				end;
			end;}
		end;
end.