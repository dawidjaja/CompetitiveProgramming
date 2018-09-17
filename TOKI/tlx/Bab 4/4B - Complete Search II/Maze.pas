var
	my,mx,iy,ix,y,x,i,num,pd,pb:integer;
	qy,qx,qs:array[0..20000] of integer;
	tnd:array[0..1000,0..1000] of integer;
	by,bx:array[1..4] of integer;
begin
//reading

readln(my,mx);
for iy:=1 to my do
	begin
	for ix:=1 to mx do
		begin
		read(num);
		tnd[iy,ix]:=0;
		if num=-1 then
			begin
			tnd[iy,ix]:=-1;
			end;
		end;
	end;
readln(y,x);

//setup

pd:=1;
pb:=2;
qx[pd]:=x;
qy[pd]:=y;
qs[pd]:=1;
tnd[y,x]:=1;
bx[1]:=0;
by[1]:=1;
bx[2]:=1;
by[2]:=0;
bx[3]:=0;
by[3]:=-1;
bx[4]:=-1;
by[4]:=0;

//process

while pb>pd do
	begin
	if ((((qy[pd]=1) or (qx[pd]=1)) or (qy[pd]=my)) or (qx[pd]=mx)) then
		begin
		writeln(qs[pd]);
		exit;
		end
	else
		begin
		for i:=1 to 4 do
			begin
			if tnd[qy[pd]+by[i],qx[pd]+bx[i]]=0 then
				begin
				qy[pb]:=qy[pd]+by[i];
				qx[pb]:=qx[pd]+bx[i];
				tnd[qy[pb],qx[pb]]:=1;
				qs[pb]:=qs[pd]+1;
				inc(pb)
				end;
			end;
		end;
	pd:=pd+1;
	end;
end.