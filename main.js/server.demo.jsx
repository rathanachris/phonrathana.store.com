import React from 'react';

// នេះជា Next.js API function សម្រាប់ទាញទិន្នន័យនៅផ្នែក server
export async function getServerSideProps() {
  // ឧទាហរណ៍ទាញទិន្នន័យពី API (អាចជំនួសជាមួយ API ពិតប្រាកដ)
  const res = await fetch('https://jsonplaceholder.typicode.com/posts');
  const posts = await res.json();

  // បញ្ជូនទិន្នន័យទៅ component ជា props
  return {
    props: {
      posts,
    },
  };
}

// Component ដែលបង្ហាញទិន្នន័យនៅ client-side
const ServerDemo = ({ posts }) => {
  return (
    <div style={{ padding: '20px', fontFamily: 'Arial, sans-serif' }}>
      <h1>Server-Side Rendering Demo</h1>
      <p>នេះជាឧទាហរណ៍នៃទិន្នន័យដែលបានទាញពី server៖</p>
      <ul>
        {posts.slice(0, 5).map((post) => (
          <li key={post.id}>
            <h3>{post.title}</h3>
            <p>{post.body}</p>
          </li>
        ))}
      </ul>
    </div>
  );
};

export default ServerDemo; routers(:8080),
