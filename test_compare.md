# 拷贝录像时间优化
测试数据20230531 15：56-20：56 原本是29-32秒
## rsync -az 效果不如 rsync -a {#1}
***215秒  发生端口错误***


## 并行传输
第一次未设置只拷贝.avi， 把.ts 和 .jpg 全拷贝了过来，也只用了9秒。



#### rsync -az日志 [目录](#1)
[I 07/31/24 16:24:46.417 8670 8670 main.cc 86] web_server version f9dfec1
[I 07/31/24 16:24:46.417 8670 8670 main.cc 87] web_server date Thu Jul 18 09:02:37 CST 2024
[I 07/31/24 16:24:46.417 8670 8670 base_db.cc 50] Attempting to connect to MySQL databases:
[I 07/31/24 16:24:46.417 8670 8670 base_db.cc 51] Host: 172.16.133.63
[I 07/31/24 16:24:46.417 8670 8670 base_db.cc 52] Port: 3306
[I 07/31/24 16:24:46.417 8670 8670 base_db.cc 53] Username: nvidia
[I 07/31/24 16:24:46.418 8670 8670 base_db.cc 54] Password: 123
[I 07/31/24 16:24:46.418 8670 8670 base_db.cc 55] Database Name: subway_user_info
[I 07/31/24 16:24:46.425 8670 8670 base_db.cc 61] Connect user nvidia connect state 0

[I 07/31/24 16:25:09.589 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:09.589 8670 8681 request_handler.cc 17] key cmd_type value record_range_copy
[I 07/31/24 16:25:09.589 8670 8681 request_handler.cc 17] key date value 20230531155600|20230531205600
[I 07/31/24 16:25:09.589 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:09.589 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:09.589 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:09.590 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:09.590 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:09.590 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:09.590 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:09.590 8670 8681 subway_app.cc 991] RecordDateCopy enter

[I 07/31/24 16:25:09.590 8670 8681 subway_app.cc 1006] DateCopy enter

[I 07/31/24 16:25:09.608 8670 10843 subway_app.cc 1037] 现在开始计时 开始时间为： 1722414309
[I 07/31/24 16:25:09.608 8670 10843 subway_app.cc 1039] CopyHandler enter

[I 07/31/24 16:25:09.608 8670 8681 subway_app.cc 177] Command handling result: 0, message: 任务添加成功，开始拷贝
[I 07/31/24 16:25:09.608 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":"{}","result_code":0,"result_msg":"任务添加成功，开始拷贝"}

[I 07/31/24 16:25:09.616 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:09.616 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:09.616 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:09.616 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:09.616 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:09.616 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:09.616 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:09.616 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:09.616 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:09.616 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:09.616 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:09.616 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":0,"seconds":1722414309,"total_size":1},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:09.624 8670 10843 subway_app.cc 1054] CopyHandler usbdisk state 1 path /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec size 960379900 free 492331552

[I 07/31/24 16:25:10.616 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:10.616 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:10.616 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:10.616 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:10.616 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:10.617 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:10.617 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:10.617 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:10.617 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:10.617 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:10.617 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:10.617 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":0,"seconds":1,"total_size":2449500},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:11.616 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:11.616 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:11.616 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:11.616 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:11.616 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:11.616 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:11.616 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:11.616 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:11.616 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:11.616 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:11.616 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:11.616 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":0,"seconds":2,"total_size":4948812},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 0 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200330026.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 1 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200327146.near.ts

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 2 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200327146.near.avi

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 3 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200300030.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 4 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200230000.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 5 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200227155.near.ts

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 6 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200227155.near.avi

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 7 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200200004.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 8 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200130008.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 9 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200127163.near.ts

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 10 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200127163.near.avi

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 11 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200100012.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 12 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200030016.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 13 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200027174.near.ts

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 14 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200027174.near.avi

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 15 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200000019.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 16 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195930023.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 17 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195927178.near.ts

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 18 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195927178.near.avi

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 19 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195900027.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 20 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195830031.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 21 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195827181.near.ts

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 22 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195827181.near.avi

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 23 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195800001.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 24 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195730005.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 25 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195727195.near.ts

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 26 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195727195.near.avi

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 27 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195700009.jpg

[I 07/31/24 16:25:11.665 8670 10843 subway_app.cc 1152] ex_from: i 28 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195630013.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 29 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195627202.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 30 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195627202.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 31 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195600016.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 32 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195530020.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 33 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195527212.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 34 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195527212.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 35 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195500024.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 36 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195430028.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 37 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195427210.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 38 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195427210.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 39 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195400032.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 40 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195330002.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 41 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195327228.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 42 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195327228.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 43 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195300006.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 44 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195230010.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 45 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195227225.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 46 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195227225.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 47 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195200014.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 48 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195130017.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 49 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195127242.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 50 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195127242.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 51 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195100021.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 52 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195030025.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 53 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195027247.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 54 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195027247.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 55 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195000029.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 56 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194930033.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 57 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194927248.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 58 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194927248.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 59 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194900003.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 60 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194830007.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 61 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194827259.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 62 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194827259.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 63 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194800011.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 64 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194730014.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 65 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194727265.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 66 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194727265.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 67 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194700018.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 68 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194630022.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 69 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194627274.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 70 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194627274.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 71 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194600026.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 72 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194530030.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 73 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194527285.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 74 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194527285.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 75 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194500000.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 76 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194430004.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 77 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194427292.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 78 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194427292.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 79 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194400008.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 80 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194330012.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 81 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194327298.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 82 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194327298.near.avi

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 83 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194300015.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 84 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194230019.jpg

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 85 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194227311.near.ts

[I 07/31/24 16:25:11.666 8670 10843 subway_app.cc 1152] ex_from: i 86 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194227311.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 87 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194200023.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 88 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194130027.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 89 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194127318.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 90 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194127318.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 91 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194100031.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 92 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194030001.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 93 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194027321.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 94 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194027321.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 95 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194000005.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 96 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193930009.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 97 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193927331.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 98 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193927331.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 99 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193900013.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 100 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193830016.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 101 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193827342.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 102 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193827342.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 103 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193800020.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 104 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193730024.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 105 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193727344.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 106 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193727344.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 107 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193700028.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 108 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193630032.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 109 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193627353.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 110 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193627353.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 111 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193600002.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 112 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193530006.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 113 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193527362.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 114 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193527362.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 115 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193500010.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 116 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193430013.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 117 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193427371.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 118 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193427371.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 119 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193400017.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 120 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193330021.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 121 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193327380.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 122 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193327380.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 123 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193300025.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 124 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193230029.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 125 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193227382.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 126 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193227382.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 127 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193200032.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 128 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193130003.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 129 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193127389.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 130 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193127389.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 131 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193100007.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 132 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193030011.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 133 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193027400.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 134 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193027400.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 135 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193000014.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 136 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192930018.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 137 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192927402.near.ts

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 138 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192927402.near.avi

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 139 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192900022.jpg

[I 07/31/24 16:25:11.667 8670 10843 subway_app.cc 1152] ex_from: i 140 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192830026.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 141 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192827417.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 142 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192827417.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 143 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192800030.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 144 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192730000.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 145 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192727421.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 146 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192727421.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 147 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192700004.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 148 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192630008.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 149 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192627428.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 150 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192627428.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 151 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192600012.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 152 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192530015.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 153 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192527439.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 154 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192527439.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 155 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192500019.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 156 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192430023.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 157 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192427446.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 158 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192427446.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 159 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192400027.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 160 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192330030.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 161 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192327454.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 162 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192327454.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 163 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192300001.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 164 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192230005.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 165 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192227463.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 166 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192227463.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 167 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192200009.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 168 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192130012.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 169 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192127473.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 170 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192127473.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 171 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192100016.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 172 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192030020.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 173 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192027477.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 174 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192027477.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 175 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192000024.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 176 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191930028.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 177 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191927486.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 178 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191927486.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 179 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191900031.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 180 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191830002.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 181 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191827491.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 182 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191827491.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 183 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191800006.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 184 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191730009.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 185 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191727493.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 186 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191727493.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 187 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191700013.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 188 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191630017.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 189 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191627503.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 190 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191627503.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 191 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191600021.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 192 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191530025.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 193 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191527509.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 194 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191527509.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 195 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191500028.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 196 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191430032.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 197 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191427523.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 198 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191427523.near.avi

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 199 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191400003.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 200 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191330006.jpg

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 201 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191327524.near.ts

[I 07/31/24 16:25:11.668 8670 10843 subway_app.cc 1152] ex_from: i 202 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191327524.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 203 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191300010.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 204 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191230014.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 205 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191227530.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 206 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191227530.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 207 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191200018.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 208 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191130022.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 209 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191127539.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 210 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191127539.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 211 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191100025.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 212 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191030029.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 213 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191027551.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 214 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191027551.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 215 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191000000.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 216 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190930003.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 217 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190927559.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 218 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190927559.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 219 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190900007.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 220 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190830011.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 221 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190827562.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 222 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190827562.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 223 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190800015.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 224 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190730019.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 225 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190727570.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 226 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190727570.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 227 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190700022.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 228 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190630026.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 229 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190627581.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 230 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190627581.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 231 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190600030.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 232 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190530000.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 233 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190527583.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 234 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190527583.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 235 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190500005.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 236 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190430008.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 237 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190427589.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 238 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190427589.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 239 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190400012.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 240 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190330016.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 241 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190327601.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 242 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190327601.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 243 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190300019.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 244 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190230023.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 245 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190227617.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 246 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190227617.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 247 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190200027.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 248 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190130031.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 249 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190127620.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 250 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190127620.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 251 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190100001.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 252 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190030005.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 253 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190027632.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 254 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190027632.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 255 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190000009.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 256 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185930013.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 257 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185927637.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 258 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185927637.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 259 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185900016.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 260 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185830020.jpg

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 261 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185827640.near.ts

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 262 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185827640.near.avi

[I 07/31/24 16:25:11.669 8670 10843 subway_app.cc 1152] ex_from: i 263 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185800024.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 264 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185730028.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 265 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185727646.near.ts

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 266 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185727646.near.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 267 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185700031.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 268 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185630002.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 269 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185627656.near.ts

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 270 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185627656.near.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 271 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185600006.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 272 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185530010.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 273 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185527658.near.ts

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 274 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185527658.near.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 275 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185500013.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 276 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185430017.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 277 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185427672.near.ts

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 278 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185427672.near.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 279 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185400021.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 280 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185330025.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 281 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185327681.near.ts

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 282 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185327681.near.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 283 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185300029.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 284 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185230032.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 285 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185227698.near.ts

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 286 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185227698.near.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 287 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185200003.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 288 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185130007.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 289 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185127696.near.ts

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 290 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185127696.near.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 291 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185100010.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 292 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185030014.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 293 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185027704.near.ts

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 294 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185027704.near.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 295 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185000018.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 296 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184930022.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 297 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184927709.near.ts

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 298 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184927709.near.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 299 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184900026.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 300 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184830029.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 301 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184827726.near.ts

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 302 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184827726.near.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 303 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184800000.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 304 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184730004.jpg

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 305 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184727751.near.ts

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 306 v /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184727751.near.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 307 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531200232502.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 308 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531195932303.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 309 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531195632088.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 310 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531195331867.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 311 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531195031652.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 312 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531194731434.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 313 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531194431256.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 314 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531194131050.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 315 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531193830857.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 316 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531193530642.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 317 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531193230428.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 318 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531192930250.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 319 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531192630045.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 320 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531192329817.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 321 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531192029589.res.avi

[I 07/31/24 16:25:11.670 8670 10843 subway_app.cc 1152] ex_from: i 322 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531191729364.res.avi

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1152] ex_from: i 323 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531191429137.res.avi

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1152] ex_from: i 324 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531191128947.res.avi

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1152] ex_from: i 325 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531190828712.res.avi

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1152] ex_from: i 326 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531190528494.res.avi

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1152] ex_from: i 327 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531190228309.res.avi

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1152] ex_from: i 328 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531185928093.res.avi

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1152] ex_from: i 329 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531185627892.res.avi

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1152] ex_from: i 330 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531185327680.res.avi

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1152] ex_from: i 331 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531185027450.res.avi

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1152] ex_from: i 332 v /media/nvidia/record_nvme/camera/full//20230531/.res/20230531184727306.res.avi

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 0 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 1 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 2 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 3 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 4 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 5 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 6 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 7 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 8 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 9 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 10 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 11 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 12 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 13 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 14 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 15 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 16 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 17 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 18 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 19 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 20 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 21 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 22 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 23 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 24 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 25 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 26 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 27 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 28 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 29 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 30 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 31 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 32 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 33 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 34 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 35 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 36 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 37 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 38 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 39 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 40 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 41 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 42 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 43 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 44 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 45 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 46 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 47 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 48 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 49 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 50 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 51 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 52 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.671 8670 10843 subway_app.cc 1154] ex_to: i 53 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 54 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 55 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 56 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 57 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 58 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 59 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 60 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 61 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 62 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 63 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 64 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 65 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 66 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 67 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 68 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 69 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 70 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 71 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 72 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 73 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 74 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 75 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 76 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 77 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 78 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 79 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 80 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 81 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 82 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 83 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 84 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 85 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 86 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 87 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 88 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 89 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 90 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 91 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 92 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 93 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 94 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 95 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 96 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 97 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 98 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 99 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 100 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 101 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 102 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 103 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 104 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 105 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 106 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 107 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 108 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 109 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 110 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 111 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 112 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 113 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 114 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 115 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 116 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 117 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 118 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 119 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 120 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 121 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 122 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 123 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 124 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 125 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 126 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 127 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 128 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 129 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 130 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 131 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 132 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 133 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 134 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 135 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.672 8670 10843 subway_app.cc 1154] ex_to: i 136 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 137 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 138 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 139 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 140 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 141 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 142 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 143 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 144 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 145 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 146 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 147 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 148 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 149 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 150 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 151 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 152 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 153 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 154 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 155 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 156 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 157 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 158 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 159 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 160 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 161 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 162 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 163 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 164 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 165 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 166 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 167 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 168 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 169 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 170 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 171 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 172 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 173 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 174 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 175 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 176 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 177 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 178 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 179 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 180 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 181 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 182 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 183 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 184 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 185 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 186 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 187 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 188 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 189 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 190 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 191 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 192 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 193 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 194 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 195 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 196 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 197 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 198 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 199 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 200 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 201 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 202 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 203 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 204 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 205 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 206 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 207 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 208 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 209 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 210 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 211 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 212 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 213 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 214 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 215 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.673 8670 10843 subway_app.cc 1154] ex_to: i 216 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 217 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 218 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 219 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 220 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 221 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 222 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 223 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 224 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 225 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 226 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 227 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 228 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 229 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 230 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 231 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 232 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 233 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 234 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 235 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 236 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 237 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 238 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 239 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 240 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 241 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 242 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 243 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 244 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 245 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 246 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 247 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 248 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 249 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 250 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 251 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 252 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 253 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 254 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 255 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 256 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 257 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 258 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 259 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 260 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 261 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 262 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 263 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 264 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 265 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 266 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 267 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 268 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 269 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 270 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 271 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 272 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 273 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 274 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 275 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 276 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 277 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 278 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 279 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 280 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 281 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 282 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 283 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 284 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 285 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 286 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 287 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 288 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 289 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 290 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 291 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 292 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 293 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 294 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 295 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 296 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 297 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 298 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 299 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 300 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 301 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 302 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.674 8670 10843 subway_app.cc 1154] ex_to: i 303 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 304 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 305 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 306 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 307 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 308 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 309 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 310 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 311 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 312 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 313 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 314 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 315 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 316 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 317 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 318 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 319 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 320 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 321 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 322 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 323 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 324 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 325 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 326 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 327 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 328 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 329 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 330 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 331 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1154] ex_to: i 332 v /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1159] total_size: 5052892 usb_free: 492331552

[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1166] Copying...
[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414311
[I 07/31/24 16:25:11.675 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200327146.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:12.231 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414312
[I 07/31/24 16:25:12.231 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:25:12.231 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414312
[I 07/31/24 16:25:12.231 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200227155.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:12.616 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:12.616 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:12.616 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:12.616 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:12.616 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:12.616 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:12.616 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:12.616 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:12.616 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:12.616 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:14.639 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:14.639 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":5,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:14.640 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:14.640 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:14.640 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:14.640 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:14.640 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:14.640 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:14.640 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:14.640 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:14.640 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:14.640 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:15.127 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414315
[I 07/31/24 16:25:15.127 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:15.127 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414315
[I 07/31/24 16:25:15.127 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200127163.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:16.720 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:16.720 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":7,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:16.720 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:16.720 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:16.720 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:16.720 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:16.720 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:16.721 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:16.721 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:16.721 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:16.721 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:16.721 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:17.964 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414317
[I 07/31/24 16:25:17.964 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:17.964 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414317
[I 07/31/24 16:25:17.964 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531200027174.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:18.767 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:18.767 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":9,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:18.768 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:18.768 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:18.768 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:18.768 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:18.768 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:18.768 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:18.768 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:18.768 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:18.768 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:18.768 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:20.765 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414320
[I 07/31/24 16:25:20.765 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:20.765 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414320
[I 07/31/24 16:25:20.765 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195927178.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:20.785 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:20.785 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":11,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:20.785 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:20.785 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:20.785 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:20.785 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:20.785 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:20.785 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:20.785 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:20.785 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:20.785 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:20.785 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:22.876 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:22.876 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":13,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:22.877 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:22.877 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:22.877 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:22.877 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:22.877 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:22.877 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:22.877 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:22.877 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:22.877 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:22.877 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:23.530 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414323
[I 07/31/24 16:25:23.530 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:23.530 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414323
[I 07/31/24 16:25:23.530 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195827181.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:24.933 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:24.933 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":15,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:24.934 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:24.934 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:24.934 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:24.934 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:24.934 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:24.934 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:24.934 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:24.934 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:24.934 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:24.934 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:26.300 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414326
[I 07/31/24 16:25:26.300 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:26.300 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414326
[I 07/31/24 16:25:26.300 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195727195.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:26.999 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:26.999 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":17,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:26.999 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:26.999 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:26.999 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:27.000 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:27.000 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:27.000 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:27.000 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:27.000 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:27.000 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:27.000 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:29.054 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:29.054 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":20,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:29.054 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:29.055 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:29.055 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:29.055 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:29.055 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:29.055 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:29.055 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:29.055 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:29.055 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:29.055 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:29.084 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414329
[I 07/31/24 16:25:29.084 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:29.084 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414329
[I 07/31/24 16:25:29.084 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195627202.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:31.127 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:31.127 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":22,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:31.127 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:31.127 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:31.127 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:31.127 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:31.127 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:31.127 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:31.127 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:31.127 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:31.127 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:31.127 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:31.984 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414331
[I 07/31/24 16:25:31.984 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:31.984 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414331
[I 07/31/24 16:25:31.984 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195527212.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:33.188 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:33.188 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":24,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:33.188 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:33.188 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:33.188 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:33.188 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:33.188 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:33.188 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:33.188 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:33.188 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:33.189 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:33.189 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:34.802 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414334
[I 07/31/24 16:25:34.802 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:34.802 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414334
[I 07/31/24 16:25:34.802 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195427210.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:35.271 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:35.271 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":26,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:35.272 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:35.272 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:35.272 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:35.272 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:35.272 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:35.272 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:35.272 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:35.272 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:35.272 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:35.272 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:37.333 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:37.333 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":28,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:37.334 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:37.334 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:37.334 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:37.334 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:37.334 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:37.334 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:37.334 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:37.334 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:37.334 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:37.334 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:37.580 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414337
[I 07/31/24 16:25:37.580 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:37.580 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414337
[I 07/31/24 16:25:37.580 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195327228.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:39.418 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:39.418 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":30,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:39.419 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:39.419 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:39.419 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:39.419 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:39.419 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:39.419 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:39.419 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:39.419 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:39.419 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:39.419 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:40.402 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414340
[I 07/31/24 16:25:40.402 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:40.402 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414340
[I 07/31/24 16:25:40.402 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195227225.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:41.465 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:41.465 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":32,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:41.465 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:41.465 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:41.465 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:41.465 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:41.465 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:41.465 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:41.465 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:41.465 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:41.465 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:41.465 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:43.196 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414343
[I 07/31/24 16:25:43.196 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:43.196 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414343
[I 07/31/24 16:25:43.196 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195127242.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:43.557 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:43.557 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":34,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:43.557 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:43.557 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:43.557 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:43.557 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:43.557 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:43.557 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:43.557 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:43.557 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:43.558 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:43.558 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:45.585 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:45.585 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":36,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:45.586 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:45.586 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:45.586 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:45.586 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:45.586 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:45.586 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:45.586 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:45.586 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:45.586 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:45.586 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:46.030 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414346
[I 07/31/24 16:25:46.030 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:46.030 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414346
[I 07/31/24 16:25:46.030 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531195027247.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:47.630 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:47.630 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":38,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:47.631 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:47.631 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:47.631 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:47.631 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:47.631 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:47.631 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:47.631 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:47.631 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:47.631 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:47.631 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:48.885 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414348
[I 07/31/24 16:25:48.886 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:48.886 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414348
[I 07/31/24 16:25:48.886 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194927248.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:49.714 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:49.714 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":40,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:49.715 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:49.715 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:49.715 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:49.715 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:49.715 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:49.715 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:49.715 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:49.715 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:49.715 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:49.715 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:51.657 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414351
[I 07/31/24 16:25:51.657 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:51.657 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414351
[I 07/31/24 16:25:51.657 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194827259.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:51.732 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:51.732 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":42,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:51.733 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:51.733 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:51.733 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:51.733 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:51.733 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:51.733 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:51.733 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:51.733 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:51.733 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:51.733 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:53.772 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:53.772 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":44,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:53.773 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:53.773 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:53.773 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:53.773 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:53.773 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:53.773 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:53.773 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:53.773 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:53.773 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:53.773 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:54.508 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414354
[I 07/31/24 16:25:54.508 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:54.508 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414354
[I 07/31/24 16:25:54.508 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194727265.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:57.158 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414357
[I 07/31/24 16:25:57.158 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:57.158 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414357
[I 07/31/24 16:25:57.158 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194627274.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:25:58.466 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:25:58.466 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":49,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:25:58.467 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:25:58.467 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:25:58.467 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:25:58.467 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:25:58.467 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:25:58.467 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:25:58.467 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:25:58.467 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:25:58.467 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:25:58.467 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:25:59.954 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414359
[I 07/31/24 16:25:59.954 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:25:59.954 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414359
[I 07/31/24 16:25:59.954 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194527285.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:00.528 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:00.528 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":51,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:00.529 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:00.529 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:00.529 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:00.529 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:00.529 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:00.529 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:00.529 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:00.529 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:00.529 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:00.529 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:02.584 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:02.584 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":53,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:02.584 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:02.584 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:02.584 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:02.584 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:02.584 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:02.584 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:02.585 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:02.585 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:02.585 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:02.585 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:02.741 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414362
[I 07/31/24 16:26:02.742 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:02.742 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414362
[I 07/31/24 16:26:02.742 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194427292.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:04.629 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:04.629 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":55,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:04.630 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:04.630 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:04.630 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:04.630 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:04.630 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:04.630 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:04.630 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:04.630 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:04.630 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:04.630 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:05.529 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414365
[I 07/31/24 16:26:05.529 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:05.529 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414365
[I 07/31/24 16:26:05.529 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194327298.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:06.675 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:06.675 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":57,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:06.675 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:06.675 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:06.675 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:06.675 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:06.675 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:06.675 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:06.675 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:06.675 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:06.675 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:06.675 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:08.454 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414368
[I 07/31/24 16:26:08.454 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:08.454 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414368
[I 07/31/24 16:26:08.454 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194227311.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:08.739 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:08.739 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":59,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:08.739 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:08.739 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:08.739 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:08.739 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:08.739 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:08.739 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:08.739 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:08.739 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:08.739 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:08.739 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:10.787 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:10.787 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":61,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:10.787 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:10.787 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:10.787 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:10.787 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:10.787 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:10.787 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:10.787 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:10.787 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:10.787 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:10.787 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:11.248 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414371
[I 07/31/24 16:26:11.248 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:11.248 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414371
[I 07/31/24 16:26:11.248 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194127318.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:12.849 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:12.849 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":63,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:12.849 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:12.849 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:12.849 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:12.849 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:12.849 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:12.849 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:12.849 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:12.849 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:12.849 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:12.849 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:14.092 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414374
[I 07/31/24 16:26:14.092 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:14.092 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414374
[I 07/31/24 16:26:14.092 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531194027321.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:14.928 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:14.928 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":65,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:14.928 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:14.928 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:14.928 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:14.928 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:14.928 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:14.929 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:14.929 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:14.929 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:14.929 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:14.929 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:16.904 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414376
[I 07/31/24 16:26:16.904 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:16.904 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414376
[I 07/31/24 16:26:16.904 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193927331.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:17.009 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:17.009 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":68,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:17.010 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:17.010 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:17.010 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:17.010 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:17.010 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:17.010 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:17.010 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:17.010 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:17.010 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:17.010 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:19.117 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:19.117 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":70,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:19.117 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:19.117 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:19.117 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:19.117 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:19.117 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:19.118 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:19.118 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:19.118 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:19.118 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:19.118 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:19.690 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414379
[I 07/31/24 16:26:19.690 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:19.690 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414379
[I 07/31/24 16:26:19.690 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193827342.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:21.152 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:21.152 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":72,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:21.152 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:21.152 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:21.152 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:21.152 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:21.152 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:21.152 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:21.152 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:21.152 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:21.152 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:21.152 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:22.552 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414382
[I 07/31/24 16:26:22.552 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:22.552 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414382
[I 07/31/24 16:26:22.552 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193727344.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:23.214 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:23.214 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":74,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:23.216 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:23.216 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:23.216 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:23.216 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:23.216 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:23.216 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:23.216 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:23.216 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:23.216 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:23.216 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:25.232 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:25.232 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":76,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:25.232 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:25.232 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:25.232 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:25.232 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:25.232 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:25.232 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:25.232 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:25.232 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:25.232 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:25.232 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:25.332 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414385
[I 07/31/24 16:26:25.332 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:25.332 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414385
[I 07/31/24 16:26:25.332 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193627353.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:27.317 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:27.317 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":78,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:27.317 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:27.317 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:27.317 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:27.317 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:27.318 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:27.318 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:27.318 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:27.318 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:27.318 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:27.318 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:28.164 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414388
[I 07/31/24 16:26:28.164 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:28.164 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414388
[I 07/31/24 16:26:28.164 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193527362.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:29.375 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:29.375 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":80,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:29.376 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:29.376 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:29.376 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:29.376 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:29.376 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:29.376 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:29.376 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:29.376 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:29.376 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:29.376 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:30.921 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414390
[I 07/31/24 16:26:30.921 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:30.921 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414390
[I 07/31/24 16:26:30.921 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193427371.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:31.416 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:31.416 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":82,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:31.416 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:31.416 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:31.416 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:31.416 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:31.416 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:31.416 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:31.416 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:31.417 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:31.417 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:31.417 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:33.504 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:33.504 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":84,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:33.504 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:33.504 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:33.504 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:33.504 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:33.505 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:33.505 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:33.505 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:33.505 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:33.505 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:33.505 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:33.809 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414393
[I 07/31/24 16:26:33.809 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:33.809 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414393
[I 07/31/24 16:26:33.809 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193327380.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:35.545 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:35.545 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":86,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:35.545 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:35.545 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:35.545 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:35.545 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:35.545 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:35.545 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:35.545 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:35.545 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:35.545 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:35.545 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:36.740 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414396
[I 07/31/24 16:26:36.740 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:36.741 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414396
[I 07/31/24 16:26:36.741 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193227382.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:37.612 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:37.612 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":88,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:37.613 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:37.613 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:37.613 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:37.613 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:37.613 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:37.613 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:37.613 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:37.613 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:37.613 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:37.613 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:39.532 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414399
[I 07/31/24 16:26:39.533 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:39.533 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414399
[I 07/31/24 16:26:39.533 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193127389.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:39.679 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:39.680 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":90,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:39.680 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:39.680 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:39.680 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:39.680 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:39.680 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:39.680 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:39.680 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:39.680 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:39.680 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:39.680 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:41.743 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:41.743 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":92,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:41.743 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:41.744 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:41.744 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:41.744 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:41.744 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:41.744 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:41.744 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:41.744 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:41.744 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:41.744 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:42.405 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414402
[I 07/31/24 16:26:42.405 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:42.405 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414402
[I 07/31/24 16:26:42.405 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531193027400.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:43.824 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:43.824 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":94,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:43.824 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:43.824 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:43.825 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:43.825 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:43.825 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:43.825 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:43.825 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:43.825 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:43.825 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:43.825 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:45.325 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414405
[I 07/31/24 16:26:45.325 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:45.326 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414405
[I 07/31/24 16:26:45.326 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192927402.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:45.910 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:45.910 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":96,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:45.910 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:45.910 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:45.910 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:45.910 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:45.910 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:45.910 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:45.910 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:45.910 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:45.910 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:45.910 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:47.998 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:47.998 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":98,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:47.999 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:47.999 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:47.999 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:47.999 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:47.999 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:47.999 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:47.999 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:47.999 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:47.999 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:47.999 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:48.068 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414408
[I 07/31/24 16:26:48.068 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:48.068 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414408
[I 07/31/24 16:26:48.068 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192827417.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:50.059 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:50.059 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":101,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:50.059 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:50.059 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:50.059 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:50.059 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:50.059 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:50.059 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:50.059 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:50.059 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:50.059 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:50.059 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:50.878 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414410
[I 07/31/24 16:26:50.878 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:50.878 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414410
[I 07/31/24 16:26:50.878 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192727421.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:52.084 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:52.084 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":103,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:52.084 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:52.084 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:52.084 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:52.084 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:52.085 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:52.085 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:52.085 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:52.085 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:52.085 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:52.085 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:53.629 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414413
[I 07/31/24 16:26:53.629 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:53.630 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414413
[I 07/31/24 16:26:53.630 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192627428.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:54.152 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:54.152 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":105,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:54.153 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:54.153 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:54.153 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:54.153 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:54.153 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:54.153 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:54.153 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:54.153 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:54.153 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:54.153 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:56.246 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:56.246 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":107,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:56.247 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:56.247 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:56.247 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:56.247 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:56.247 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:56.247 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:56.247 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:56.247 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:56.247 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:56.247 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:56.543 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414416
[I 07/31/24 16:26:56.543 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:56.543 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414416
[I 07/31/24 16:26:56.543 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192527439.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:26:58.316 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:26:58.316 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":109,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:26:58.316 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:26:58.316 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:26:58.316 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:26:58.316 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:26:58.316 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:26:58.317 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:26:58.317 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:26:58.317 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:26:58.317 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:26:58.317 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:26:59.471 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414419
[I 07/31/24 16:26:59.471 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:26:59.471 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414419
[I 07/31/24 16:26:59.471 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192427446.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:00.403 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:00.403 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":111,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:00.404 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:00.404 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:00.404 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:00.404 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:00.404 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:00.404 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:00.404 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:00.404 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:00.404 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:00.404 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:02.255 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414422
[I 07/31/24 16:27:02.255 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:02.255 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414422
[I 07/31/24 16:27:02.255 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192327454.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:02.447 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:02.447 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":113,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:02.448 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:02.448 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:02.448 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:02.448 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:02.448 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:02.448 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:02.448 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:02.448 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:02.448 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:02.448 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:04.541 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:04.541 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":115,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:04.541 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:04.541 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:04.541 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:04.541 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:04.541 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:04.541 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:04.541 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:04.541 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:04.541 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:04.541 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:05.105 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414425
[I 07/31/24 16:27:05.105 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:05.105 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414425
[I 07/31/24 16:27:05.105 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192227463.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:06.648 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:06.648 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":117,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:06.649 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:06.649 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:06.649 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:06.649 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:06.649 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:06.649 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:06.649 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:06.649 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:06.649 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:06.649 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:08.030 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414428
[I 07/31/24 16:27:08.030 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:08.030 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414428
[I 07/31/24 16:27:08.030 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192127473.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:08.706 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:08.706 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":119,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:08.706 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:08.706 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:08.706 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:08.706 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:08.706 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:08.706 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:08.706 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:08.706 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:08.706 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:08.706 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:10.823 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:10.823 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":121,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:10.823 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:10.823 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:10.823 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:10.823 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:10.823 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:10.823 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:10.823 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:10.823 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:10.823 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:10.823 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:10.851 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414430
[I 07/31/24 16:27:10.851 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:10.851 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414430
[I 07/31/24 16:27:10.851 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531192027477.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:12.907 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:12.907 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":123,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:12.908 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:12.908 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:12.908 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:12.908 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:12.908 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:12.908 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:12.908 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:12.908 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:12.908 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:12.908 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:13.676 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414433
[I 07/31/24 16:27:13.676 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:13.676 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414433
[I 07/31/24 16:27:13.676 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191927486.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:14.948 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:14.948 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":125,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:14.948 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:14.948 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:14.948 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:14.948 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:14.948 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:14.948 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:14.948 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:14.948 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:14.948 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:14.948 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:16.523 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414436
[I 07/31/24 16:27:16.523 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:16.523 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414436
[I 07/31/24 16:27:16.523 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191827491.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:17.032 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:17.032 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":128,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:17.033 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:17.033 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:17.033 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:17.033 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:17.033 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:17.033 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:17.033 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:17.033 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:17.033 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:17.033 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:19.110 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:19.110 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":130,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:19.111 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:19.111 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:19.111 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:19.111 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:19.111 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:19.111 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:19.111 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:19.111 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:19.111 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:19.111 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:19.432 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414439
[I 07/31/24 16:27:19.433 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:19.433 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414439
[I 07/31/24 16:27:19.433 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191727493.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:21.954 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414441
[I 07/31/24 16:27:21.954 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:21.954 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414441
[I 07/31/24 16:27:21.954 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191627503.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:24.590 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414444
[I 07/31/24 16:27:24.590 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:24.590 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414444
[I 07/31/24 16:27:24.590 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191527509.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:26.397 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:26.397 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":137,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:26.398 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:26.398 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:26.398 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:26.398 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:26.398 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:26.398 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:26.398 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:26.398 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:26.398 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:26.398 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:27.591 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414447
[I 07/31/24 16:27:27.591 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 3 seconds

[I 07/31/24 16:27:27.591 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414447
[I 07/31/24 16:27:27.591 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191427523.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:28.449 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:28.449 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":139,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:28.450 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:28.450 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:28.450 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:28.450 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:28.450 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:28.450 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:28.450 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:28.450 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:28.450 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:28.450 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:30.354 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414450
[I 07/31/24 16:27:30.354 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:30.354 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414450
[I 07/31/24 16:27:30.354 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191327524.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:30.514 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:30.514 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":141,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:30.515 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:30.515 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:30.515 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:30.515 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:30.515 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:30.515 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:30.515 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:30.515 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:30.515 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:30.515 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:32.618 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:32.618 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":143,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:32.619 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:32.619 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:32.619 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:32.619 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:32.619 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:32.619 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:32.619 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:32.619 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:32.619 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:32.619 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:33.198 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414453
[I 07/31/24 16:27:33.198 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:33.198 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414453
[I 07/31/24 16:27:33.198 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191227530.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:34.717 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:34.717 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":145,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:34.717 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:34.717 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:34.717 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:34.717 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:34.717 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:34.717 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:34.717 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:34.717 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:34.717 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:34.717 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:35.981 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414455
[I 07/31/24 16:27:35.982 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:35.982 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414455
[I 07/31/24 16:27:35.982 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191127539.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:36.787 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:36.787 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":147,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:36.788 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:36.788 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:36.788 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:36.788 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:36.788 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:36.788 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:36.788 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:36.788 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:36.788 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:36.788 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:38.799 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414458
[I 07/31/24 16:27:38.799 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:38.799 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414458
[I 07/31/24 16:27:38.799 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531191027551.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:38.885 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:38.885 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":149,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:38.885 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:38.885 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:38.885 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:38.885 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:38.885 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:38.886 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:38.886 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:38.886 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:38.886 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:38.886 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:41.003 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:41.003 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":152,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:41.003 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:41.003 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:41.003 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:41.003 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:41.003 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:41.003 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:41.003 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:41.003 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:41.004 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:41.004 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:41.591 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414461
[I 07/31/24 16:27:41.591 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:41.591 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414461
[I 07/31/24 16:27:41.591 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190927559.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:43.128 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:43.128 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":154,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:43.128 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:43.128 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:43.128 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:43.128 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:43.128 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:43.128 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:43.128 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:43.128 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:43.128 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:43.128 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:44.380 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414464
[I 07/31/24 16:27:44.380 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:44.380 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414464
[I 07/31/24 16:27:44.380 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190827562.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:45.218 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:45.218 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":156,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:45.219 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:45.219 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:45.219 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:45.219 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:45.219 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:45.219 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:45.219 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:45.219 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:45.219 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:45.219 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:47.255 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414467
[I 07/31/24 16:27:47.255 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:47.255 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414467
[I 07/31/24 16:27:47.255 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190727570.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:47.321 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:47.321 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":158,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:47.322 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:47.322 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:47.322 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:47.322 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:47.322 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:47.322 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:47.322 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:47.322 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:47.322 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:47.322 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:49.410 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:49.410 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":160,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:49.410 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:49.410 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:49.410 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:49.410 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:49.410 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:49.410 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:49.410 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:49.410 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:49.410 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:49.410 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:50.061 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414470
[I 07/31/24 16:27:50.061 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:50.061 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414470
[I 07/31/24 16:27:50.061 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190627581.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:51.497 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:51.498 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":162,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:51.498 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:51.498 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:51.498 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:51.498 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:51.498 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:51.498 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:51.498 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:51.498 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:51.498 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:51.498 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:52.859 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414472
[I 07/31/24 16:27:52.859 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:52.859 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414472
[I 07/31/24 16:27:52.859 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190527583.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:53.611 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:53.611 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":164,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:53.611 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:53.611 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:53.611 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:53.611 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:53.611 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:53.611 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:53.611 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:53.611 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:53.612 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:53.612 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:55.623 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414475
[I 07/31/24 16:27:55.623 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:55.623 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414475
[I 07/31/24 16:27:55.623 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190427589.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:55.686 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:55.686 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":166,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:55.686 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:55.686 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:55.686 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:55.686 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:55.686 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:55.686 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:55.686 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:55.686 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:55.686 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:55.686 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:57.793 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:57.793 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":168,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:57.794 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:57.794 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:57.794 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:57.794 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:57.794 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:57.794 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:57.794 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:57.794 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:57.794 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:57.794 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:27:58.482 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414478
[I 07/31/24 16:27:58.482 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:27:58.482 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414478
[I 07/31/24 16:27:58.482 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190327601.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:27:59.871 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:27:59.871 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":170,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:27:59.871 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:27:59.871 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:27:59.871 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:27:59.871 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:27:59.871 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:27:59.871 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:27:59.871 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:27:59.871 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:27:59.871 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:27:59.871 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:01.215 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414481
[I 07/31/24 16:28:01.216 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:01.216 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414481
[I 07/31/24 16:28:01.216 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190227617.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:01.988 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:01.988 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":172,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:01.988 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:01.988 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:01.988 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:01.988 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:01.989 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:01.989 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:01.989 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:01.989 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:01.989 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:01.989 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:03.828 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414483
[I 07/31/24 16:28:03.828 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:03.828 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414483
[I 07/31/24 16:28:03.828 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190127620.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:04.111 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:04.112 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":175,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:04.112 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:04.112 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:04.112 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:04.112 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:04.112 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:04.112 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:04.112 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:04.112 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:04.112 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:04.112 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:06.182 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:06.182 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":177,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:06.182 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:06.182 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:06.183 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:06.183 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:06.183 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:06.183 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:06.183 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:06.183 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:06.183 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:06.183 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:06.594 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414486
[I 07/31/24 16:28:06.594 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:06.594 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414486
[I 07/31/24 16:28:06.594 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531190027632.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:08.268 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:08.268 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":179,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:08.268 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:08.268 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:08.268 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:08.268 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:08.268 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:08.269 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:08.269 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:08.269 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:08.269 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:08.269 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:09.428 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414489
[I 07/31/24 16:28:09.428 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:09.428 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414489
[I 07/31/24 16:28:09.428 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185927637.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:10.385 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:10.385 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":181,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:10.386 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:10.386 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:10.386 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:10.386 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:10.386 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:10.386 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:10.386 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:10.386 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:10.386 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:10.386 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:12.333 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414492
[I 07/31/24 16:28:12.333 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:12.333 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414492
[I 07/31/24 16:28:12.333 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185827640.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:12.451 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:12.451 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":183,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:12.451 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:12.451 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:12.451 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:12.451 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:12.451 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:12.451 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:12.451 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:12.451 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:12.451 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:12.451 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:14.575 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:14.575 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":185,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:14.575 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:14.576 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:14.576 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:14.576 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:14.576 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:14.576 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:14.576 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:14.576 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:14.576 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:14.576 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:15.069 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414495
[I 07/31/24 16:28:15.069 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:15.069 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414495
[I 07/31/24 16:28:15.069 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185727646.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:16.636 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:16.636 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":187,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:16.637 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:16.637 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:16.637 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:16.637 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:16.637 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:16.637 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:16.637 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:16.637 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:16.637 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:16.637 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:17.828 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414497
[I 07/31/24 16:28:17.828 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:17.828 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414497
[I 07/31/24 16:28:17.828 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185627656.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:18.719 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:18.719 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":189,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:18.719 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:18.719 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:18.719 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:18.719 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:18.719 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:18.719 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:18.719 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:18.719 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:18.719 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:18.719 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:20.766 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414500
[I 07/31/24 16:28:20.766 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:20.766 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414500
[I 07/31/24 16:28:20.766 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185527658.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:20.821 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:20.821 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":191,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:20.821 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:20.821 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:20.821 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:20.821 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:20.821 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:20.821 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:20.821 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:20.821 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:20.822 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:20.822 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:22.897 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:22.897 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":193,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:22.897 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:22.897 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:22.897 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:22.897 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:22.897 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:22.897 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:22.897 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:22.897 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:22.897 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:22.897 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:23.507 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414503
[I 07/31/24 16:28:23.507 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:23.507 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414503
[I 07/31/24 16:28:23.507 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185427672.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:24.993 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:24.994 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":195,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:24.994 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:24.994 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:24.994 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:24.995 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:24.995 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:24.995 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:24.995 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:24.995 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:24.995 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:24.995 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:26.161 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414506
[I 07/31/24 16:28:26.161 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:26.161 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414506
[I 07/31/24 16:28:26.161 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185327681.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:27.140 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:27.140 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":198,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:27.141 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:27.141 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:27.141 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:27.141 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:27.141 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:27.141 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:27.141 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:27.141 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:27.141 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:27.141 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:28.913 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414508
[I 07/31/24 16:28:28.913 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:28.913 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414508
[I 07/31/24 16:28:28.913 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185227698.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:29.221 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:29.221 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":200,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:29.221 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:29.221 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:29.221 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:29.221 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:29.221 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:29.221 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:29.221 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:29.221 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:29.222 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:29.222 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:31.339 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:31.339 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":202,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:31.340 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:31.340 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:31.340 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:31.340 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:31.340 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:31.340 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:31.340 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:31.340 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:31.340 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:31.340 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:31.692 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414511
[I 07/31/24 16:28:31.692 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:31.693 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414511
[I 07/31/24 16:28:31.693 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185127696.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:33.406 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:33.406 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":204,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:33.407 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:33.407 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:33.407 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:33.407 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:33.407 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:33.407 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:33.407 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:33.407 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:33.407 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:33.407 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:34.468 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414514
[I 07/31/24 16:28:34.468 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:34.468 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414514
[I 07/31/24 16:28:34.468 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531185027704.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:37.103 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414517
[I 07/31/24 16:28:37.103 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:37.103 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414517
[I 07/31/24 16:28:37.103 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184927709.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:39.575 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414519
[I 07/31/24 16:28:39.575 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:39.575 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414519
[I 07/31/24 16:28:39.575 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184827726.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:42.118 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414522
[I 07/31/24 16:28:42.118 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:42.118 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414522
[I 07/31/24 16:28:42.118 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/6mm/20230531184727751.near.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/6mm
[I 07/31/24 16:28:43.180 8670 8681 subway_app.cc 177] Command handling result: 0, message: 正在拷贝
[I 07/31/24 16:28:43.181 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":214,"total_size":5052892},"result_code":0,"result_msg":"正在拷贝"}

[I 07/31/24 16:28:43.181 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:43.181 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:43.181 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:43.181 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:43.181 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:43.181 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:43.181 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:43.181 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:43.181 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:43.181 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:44.864 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.864 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 2 seconds

[I 07/31/24 16:28:44.870 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.870 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531200232502.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.877 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.877 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.878 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.878 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531195932303.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.885 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.885 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.885 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.885 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531195632088.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.892 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.892 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.892 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.892 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531195331867.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.899 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.899 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.899 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.899 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531195031652.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.906 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.906 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.906 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.906 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531194731434.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.916 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.916 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.916 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.916 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531194431256.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.924 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.924 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.924 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.924 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531194131050.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.937 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.937 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.937 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.937 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531193830857.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.945 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.945 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.945 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.945 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531193530642.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.953 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.953 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.953 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.953 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531193230428.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.961 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.961 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.961 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.961 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531192930250.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.968 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.968 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.968 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.968 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531192630045.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.976 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.976 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.976 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.976 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531192329817.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.987 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.987 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.987 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.987 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531192029589.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:44.998 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414524
[I 07/31/24 16:28:44.998 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:44.998 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414524
[I 07/31/24 16:28:44.998 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531191729364.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:45.008 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414525
[I 07/31/24 16:28:45.008 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:45.008 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414525
[I 07/31/24 16:28:45.008 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531191429137.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:45.015 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414525
[I 07/31/24 16:28:45.015 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:45.015 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414525
[I 07/31/24 16:28:45.015 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531191128947.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:45.023 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414525
[I 07/31/24 16:28:45.023 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:45.023 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414525
[I 07/31/24 16:28:45.023 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531190828712.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:45.030 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414525
[I 07/31/24 16:28:45.030 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:45.030 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414525
[I 07/31/24 16:28:45.030 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531190528494.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:45.040 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414525
[I 07/31/24 16:28:45.040 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:45.040 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414525
[I 07/31/24 16:28:45.040 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531190228309.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:45.047 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414525
[I 07/31/24 16:28:45.047 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:45.047 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414525
[I 07/31/24 16:28:45.047 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531185928093.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:45.054 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414525
[I 07/31/24 16:28:45.054 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:45.054 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414525
[I 07/31/24 16:28:45.054 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531185627892.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:45.063 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414525
[I 07/31/24 16:28:45.063 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:45.063 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414525
[I 07/31/24 16:28:45.063 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531185327680.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:45.070 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414525
[I 07/31/24 16:28:45.070 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:45.070 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414525
[I 07/31/24 16:28:45.070 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531185027450.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:45.077 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414525
[I 07/31/24 16:28:45.077 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:45.077 8670 10843 subway_app.cc 1356] ExecuteCopyCommand start time: 1722414525
[I 07/31/24 16:28:45.077 8670 10843 subway_app.cc 1365] ExecuteCopyCommand will execute cmd: rsync -az /media/nvidia/record_nvme/camera/full//20230531/.res/20230531184727306.res.avi /media/nvidia/539b83f5-49b7-4723-bf7e-dcc202d899ec/subway/userdisk/record_nvme/camera/full//20230531/.res
[I 07/31/24 16:28:45.084 8670 10843 subway_app.cc 1373] ExecuteCopyCommand end time: 1722414525
[I 07/31/24 16:28:45.085 8670 10843 subway_app.cc 1374] ExecuteCopyCommand total duration: 0 seconds

[I 07/31/24 16:28:45.089 8670 10843 subway_app.cc 1209] Copy and sync done, code 1
[I 07/31/24 16:28:45.089 8670 10843 subway_app.cc 1075] CopyHandler exit state 1
[I 07/31/24 16:28:45.089 8670 10843 subway_app.cc 1079] 现在结束 结束时间为1722414525
[I 07/31/24 16:28:45.089 8670 10843 subway_app.cc 1080] 总共耗时：215秒

[I 07/31/24 16:28:45.293 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.293 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":216,"total_size":5052892},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.293 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.293 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.293 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.293 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.294 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.294 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.294 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.294 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.294 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.294 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.294 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.294 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.294 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.294 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.294 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.294 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.294 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.294 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.294 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.295 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.295 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.295 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.295 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.295 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.295 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.295 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.295 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.295 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.295 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.295 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.295 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.295 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.295 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.295 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.295 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.295 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.296 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.296 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.296 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.296 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.296 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.296 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.296 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.296 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.296 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.296 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.296 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.296 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.296 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.296 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.296 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.296 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.297 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.297 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.297 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.297 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.297 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.297 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.297 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.298 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.298 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.298 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.298 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.298 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.298 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.298 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.298 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.298 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.298 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.298 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.299 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.299 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.299 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.299 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.299 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.299 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.299 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.299 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.299 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.299 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.299 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.300 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.300 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.300 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.300 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.300 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.300 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.300 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.300 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.300 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.300 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.300 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.300 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.300 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.301 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.301 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.301 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.301 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.301 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.301 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.301 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.301 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.301 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.301 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.301 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.301 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.301 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.302 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.302 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.302 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.302 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.302 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.302 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.302 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.302 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.302 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.302 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.302 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.302 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.303 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.303 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.303 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.303 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.303 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.303 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.303 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.303 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.303 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.303 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.303 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.304 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.304 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.305 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.305 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.305 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.305 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.305 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.305 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.305 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.305 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.305 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.305 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.305 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.305 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.305 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.306 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.306 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.307 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.307 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.308 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.308 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.309 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.309 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.309 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.309 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.309 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.309 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.309 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.309 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.309 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.309 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.309 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.309 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.310 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.310 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.311 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.311 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.311 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.311 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.311 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.311 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.311 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.311 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.311 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.311 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.311 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.311 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.312 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.312 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.313 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.313 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.314 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.314 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.315 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.315 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.316 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.316 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.316 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.316 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.316 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.316 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.316 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.316 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.316 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.316 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.316 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.316 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.317 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.317 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.317 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.317 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.317 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.317 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.317 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.317 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.317 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.317 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.317 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.318 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.318 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.319 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.319 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.319 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.319 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.319 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.319 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.319 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.319 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.319 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.319 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.319 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.319 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.320 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.320 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.320 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.320 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.320 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.320 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.320 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.320 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.320 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.320 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.320 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.321 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.321 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.322 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.322 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.323 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.323 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.323 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.323 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.323 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.323 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.323 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.323 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.323 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.323 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.323 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.324 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.324 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.325 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.325 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.326 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.326 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.327 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.327 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.327 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.327 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.327 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.327 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.327 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.327 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.327 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.327 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.327 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.328 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.328 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.329 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.329 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.329 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.329 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.329 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.329 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.329 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.329 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.329 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.329 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.329 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.329 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.329 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.330 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.330 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.330 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.330 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.330 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.330 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.330 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.330 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.330 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.330 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.330 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.330 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.330 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.331 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.331 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.331 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.331 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.331 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.331 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.331 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.331 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.331 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.331 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.331 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.331 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.332 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.332 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.332 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.332 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.332 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.332 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.332 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.332 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.332 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.332 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.332 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.332 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.333 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.333 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.334 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.334 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.335 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.335 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.335 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.335 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.335 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.335 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.335 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.335 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.335 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.335 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.335 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.336 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.336 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.337 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.337 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.338 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.338 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.338 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.338 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.338 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.338 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.338 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.338 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.338 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.338 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.338 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.338 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.339 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.339 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.340 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.340 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.340 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}

[I 07/31/24 16:28:45.340 8670 8681 request_handler.cc 15] ---------incoming-------------
[I 07/31/24 16:28:45.340 8670 8681 request_handler.cc 17] key cmd_type value get_copy_progress
[I 07/31/24 16:28:45.340 8670 8681 request_handler.cc 17] key username value zy
[I 07/31/24 16:28:45.340 8670 8681 request_handler.cc 17] key password value 21f3d99c69e2f2fe16d29a04846bc1ed
[I 07/31/24 16:28:45.340 8670 8681 subway_app.cc 84] Handle enter 
[I 07/31/24 16:28:45.340 8670 8681 subway_app.cc 93] type: 1
[I 07/31/24 16:28:45.340 8670 8681 subway_app.cc 97] session_token: 
[I 07/31/24 16:28:45.340 8670 8681 subway_app.cc 162] Session token valid.
[I 07/31/24 16:28:45.340 8670 8681 subway_app.cc 172] Handling as CLIENT_CIDI.
[I 07/31/24 16:28:45.340 8670 8681 subway_app.cc 1392] QueryRealProgress enter

[I 07/31/24 16:28:45.340 8670 8681 subway_app.cc 177] Command handling result: 1, message: 未在拷贝
[I 07/31/24 16:28:45.340 8670 8681 request_handler.cc 34] ----------Rely------------
{"data_map":{"percent":100,"seconds":0,"total_size":1},"result_code":1,"result_msg":"未在拷贝"}



## 并行传输
