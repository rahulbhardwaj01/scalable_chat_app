"use client";

import React, { useState } from "react";
import { Button } from "@/components/ui/button";
import Link from "next/link";
import { CustomUser } from "@/app/api/auth/[...nextauth]/options";
import LoginModal from "../auth/LoginModal";

export default function HeroSection({ user }: { user?: CustomUser }) {
  const [isModalOpen, setIsModalOpen] = useState(false);

  const handleModalClose = () => setIsModalOpen(false);
  const handleBtnClick = (e: React.MouseEvent) => {
    if (!user) {
      e.preventDefault();
      setIsModalOpen(true);
    }
  };

  return (
    <section className='flex-1 flex flex-col items-center justify-center text-center p-12 bg-gradient-to-b from-gray-50 to-white'>
      <h1 className='text-5xl font-extrabold text-gray-900 mb-4'>
        Instant Chat Links for Seamless Conversations. Send messages as well as images and files!!
      </h1>
      <p className='text-xl text-gray-600 mb-8'>
        ChatBappa makes it effortless to create secure chat links and start
        conversations in seconds.
      </p>

      {/* Button logic to open login modal if user is not logged in */}
      <Link href={user ? "/dashboard" : "#"} onClick={handleBtnClick}>
        <Button size='lg' className='animate-pulse'>
          Start Chatting
        </Button>
      </Link>

      <div className='mt-12 w-full max-w-5xl flex justify-center'>
        {/* Placeholder for Illustration/Image */}
        <img
          src='/images/conversation.svg'
          alt='Illustration'
          className='w-full h-auto'
        />
      </div>

      {/* Render the LoginModal component */}
      <LoginModal isOpen={isModalOpen} onClose={handleModalClose} />
    </section>
  );
}
