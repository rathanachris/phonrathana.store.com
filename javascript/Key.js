import dotenv from "dotenv";
dotenv.config();

console.log("Firebase Key:", process.env.FIREBASE_API_KEY);
console.log("odserver URI:", process.env.MONGO_URI);
