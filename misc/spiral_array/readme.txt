一个ｎ行ｎ列的螺旋矩阵可由如下方法生成：
从矩阵左上方开始（第１行第１列）出发，初始向右移动，从１开始，每经历一个格子写入一个数；如果前方是未曾经过的格子则继续前进，否则右转；重复操作直至所有格子被写满。譬如
１　　２　　３　　４
１２　１３　１４　５
１１　１６　１５　６
１０　９　　８　　７
求对任意一个ｎ×ｎ矩阵，第ｉ行ｊ列的数是多少？
解题：
所要查询的数（ｉ，ｊ）在第ｑ圈
ｑ＝ｍｉｎ（ｉ，ｊ，ｎ－ｉ＋１，ｎ－ｊ＋１）
第ｑ圈有４(n-q(n-1))-4个数
所要查询的数（ｉ，ｊ）在第ｑ圈
ｑ＝ｍｉｎ（ｉ，ｊ，ｎ－ｉ＋１，ｎ－ｊ＋１）
第ｑ圈有４(n-２(ｑ-1))-4个数，前ｑ圈共有q * (n - q) * 4个数。
目标数距离本圈第一个数的位置由（ｉ，ｊ）的位置决定：如果（ｉ，ｊ）在上或右（此时ｉ≤ｊ），则为(q - 1) * (n - (q - 1)) * 4＋i+j-2q+1。如果（ｉ，ｊ）在下或左（此时ｉ≥ｊ），则为q * (n - q) * 4 - (i + j - 2 * q + 1) + 2
