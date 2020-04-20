// class aduh extends Thread {
//         String vote;
//         public aduh(String vote) {
//             this.vote = vote;
//         }

//         public void run() {
//             if (verify(vote)) {
//                 addVote(vote);
//             }
//         }
//     }

//     public Thread receiveVote(String vote) {
//         // ubah kode berikut agar mengembalikan thread yang akan menambah vote
//         // PENTING: jangan start thread, cukup return saja
//         // if (verify(vote)) {
//         //     addVote(vote);
//         // }
//         return new aduh(vote);
//     }