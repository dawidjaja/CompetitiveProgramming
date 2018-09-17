var
	list:array[0..100] of string;
	skor:array[0..100,1..3] of longint;
	dummy,i,j,msk,t1,t2,t3,temp,s1,s2,s3,cek,jmlh,bts:longint;
	id,ss,zzz:string;
	a,b,c,d,e:char;
begin
	readln(msk);
	for dummy:=1 to msk do
		begin
		readln(jmlh,bts);
		read(a,b,c,d,e);
		id:=a+b+c+d+e;
		readln(zzz);
		for i:=1 to jmlh do
			begin
			read(a,b,c,d,e);
			ss:=a+b+c+d+e;
			list[i]:=ss;
			readln(t1,t2,t3);
			skor[i,1]:=t1;
			skor[i,2]:=t2;
			skor[i,3]:=t3;
			end;
		cek:=0;
		for i:=1 to bts do
			begin
			temp:=i;
			for j:=i+1 to jmlh do
				begin
				if skor[j,3]>skor[temp,3] then
					begin
					temp:=j;
					end
				else
					begin
					if skor[j,3]=skor[temp,3] then
						begin
						if skor[j,2]>skor[temp,2] then
							begin
							temp:=j;
							end
						else
							begin
							if skor[j,2]=skor[temp,2] then
								begin
								if skor[j,1]>skor[temp,1] then
									begin
									temp:=j;
									end;
								end;
							end;
						end;
					end;
				end;
			ss:=list[temp];
			s1:=skor[temp,1];
			s2:=skor[temp,2];
			s3:=skor[temp,3];
			list[temp]:=list[i];
			skor[temp,1]:=skor[i,1];
			skor[temp,2]:=skor[i,2];
			skor[temp,3]:=skor[i,3];
			list[i]:=ss;
			skor[i,1]:=s1;
			skor[i,2]:=s2;
			skor[i,3]:=s3;
			if list[i]=id then
				begin
				cek:=1;
				writeln('YA');
				break;
				end;
			end;
		if cek=0 then
			begin
			writeln('TIDAK');
			end;
		end;
end.