var
    temp,luas:real;
    msk,i,j,k,cek:longint;
    ty,tx:array[0..400] of longint;
begin
readln(msk);
if msk<=2 then
    begin
    writeln('-1.00');
    end
else
    begin
    for i:=1 to msk do
        begin
        readln(tx[i],ty[i]);
        end;
    cek:=0;
    temp:=2000000000;
    for i:=1 to msk-2 do
        begin
        for j:=i+1 to msk-1 do
            begin
            for k:=j+1 to msk do
                begin
                luas:=abs((((tx[i]*ty[j])+(tx[j]*ty[k])+(tx[k]*ty[i]))-((ty[i]*tx[j])+(ty[j]*tx[k])+(ty[k]*tx[i])))/2);
                if luas=temp then
                    begin
                    cek:=0;
                    end;
                if (luas<temp) and (luas>0) then
                    begin
                    temp:=luas;
                    cek:=1;
                    end;
                end;
            end;
        end;
    if cek=1 then
        begin
        writeln(temp:0:2);
        end
    else
        begin
        writeln('-1.00');
        end;
    end;
end.