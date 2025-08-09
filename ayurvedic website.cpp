/*
Startup name suggestions (pick one or mix):
1. Niramaya (Sanskrit: "free from disease")
2. ArogyaRoot
3. DravyaWell
4. SattvaLab
5. OjasRitual
6. PrakritiPulse
7. AyurvedaMitra

Logo concepts (SVGs included below as React components):
- Concept A (Niramaya): stylized leaf + mortar-pestle, circular, calming green.
- Concept B (OjasRitual): sun + drop (vitality + oil), warm amber.
- Concept C (SattvaLab): minimal monogram 'S' formed by two herbal leaves, modern premium look.

Use these names/logos as starting points. You can request PNG/JPEG/SVG exports or ask me to generate refined logos with color palettes.

----
This single-file React component is a ready-to-run landing page built with Tailwind CSS classes.
It includes:
- Hero with CTA
- Product cards for 3 MVP SKUs
- Wellness quiz modal (simple flow)
- Pre-order form with email capture (mocked POST handler)
- Inline SVG logo components (3 variants) you can pick from

To preview:
- Place this file in a React app (Vite or Create React App)
- Ensure Tailwind is configured. The component uses Tailwind utility classes.

*/

import React, { useState } from "react";

/* ---------- Inline SVG Logo Components ---------- */
function LogoA({ className = "h-10 w-10" }) {
  return (
    <svg className={className} viewBox="0 0 64 64" fill="none" xmlns="http://www.w3.org/2000/svg">
      <circle cx="32" cy="32" r="30" fill="#E6F7EE" stroke="#2F855A" strokeWidth="2" />
      <path d="M20 36c4-8 12-12 20-10" stroke="#276749" strokeWidth="3" strokeLinecap="round" strokeLinejoin="round" />
      <path d="M28 44c0-6 8-10 12-8" stroke="#276749" strokeWidth="3" strokeLinecap="round" strokeLinejoin="round" />
      <rect x="28" y="20" width="8" height="8" rx="2" fill="#2F855A" />
    </svg>
  );
}

function LogoB({ className = "h-10 w-10" }) {
  return (
    <svg className={className} viewBox="0 0 64 64" fill="none" xmlns="http://www.w3.org/2000/svg">
      <rect x="2" y="2" width="60" height="60" rx="12" fill="#FFF7ED" />
      <path d="M32 14c6 0 10 6 10 12s-4 10-10 10-10-4-10-10 4-12 10-12z" fill="#D69E2E" />
      <path d="M32 36c6 0 10 6 10 12H22c0-6 4-12 10-12z" fill="#E97721" />
    </svg>
  );
}

function LogoC({ className = "h-10 w-10" }) {
  return (
    <svg className={className} viewBox="0 0 64 64" fill="none" xmlns="http://www.w3.org/2000/svg">
      <circle cx="32" cy="32" r="30" fill="#F0FFF4" />
      <path d="M20 36c4-8 20-8 24 0" stroke="#1E6F3A" strokeWidth="3" strokeLinecap="round" strokeLinejoin="round" />
      <path d="M26 30c3-4 10-4 13 0" stroke="#1E6F3A" strokeWidth="2.5" strokeLinecap="round" />
    </svg>
  );
}

/* ---------- Main Component ---------- */
export default function AyurvedaLanding() {
  const [showQuiz, setShowQuiz] = useState(false);
  const [quizStep, setQuizStep] = useState(0);
  const [quizAnswers, setQuizAnswers] = useState({});
  const [email, setEmail] = useState("");
  const [preorderSuccess, setPreorderSuccess] = useState(false);

  const products = [
    {
      id: "reboot",
      title: "7-Day Ayurvedic Reboot Kit",
      price: "₹999",
      desc: "Personalized ritual kit — oil/tea + ritual card. Trial-friendly."
    },
    {
      id: "hair",
      title: "Personalized Hair Regimen Starter",
      price: "₹1299",
      desc: "Monthly oil + serum follow-up subscription. Targets hair fall & shine."
    },
    {
      id: "corporate",
      title: "Corporate Wellness Pilot (8 weeks)",
      price: "Custom",
      desc: "Onboarding quiz + 2 sends + group webinar with Ayurvedic expert."
    }
  ];

  function handleQuizAnswer(key, value) {
    setQuizAnswers((q) => ({ ...q, [key]: value }));
    setQuizStep((s) => s + 1);
  }

  function submitPreorder(e) {
    e.preventDefault();
    if (!email) return alert("Please enter an email");
    // mock POST — in production call API
    setTimeout(() => setPreorderSuccess(true), 600);
  }

  function resetQuiz() {
    setQuizAnswers({});
    setQuizStep(0);
    setShowQuiz(false);
  }

  return (
    <div className="min-h-screen bg-white text-gray-800">
      <header className="max-w-6xl mx-auto px-6 py-6 flex items-center justify-between">
        <div className="flex items-center gap-3">
          <LogoA />
          <div>
            <h1 className="font-bold text-lg">Niramaya</h1>
            <p className="text-xs text-gray-500">Ayurveda • Personalization • Science</p>
          </div>
        </div>
        <nav className="space-x-4 hidden md:flex">
          <a className="text-sm hover:underline" href="#products">Products</a>
          <a className="text-sm hover:underline" href="#how">How it works</a>
          <a className="text-sm hover:underline" onClick={() => setShowQuiz(true)} href="#quiz">Take Quiz</a>
        </nav>
        <div className="flex items-center gap-3">
          <button onClick={() => setShowQuiz(true)} className="bg-green-600 text-white px-4 py-2 rounded-md text-sm">Take Quiz</button>
        </div>
      </header>

      <main className="max-w-6xl mx-auto px-6">
        <section className="grid grid-cols-1 md:grid-cols-2 gap-8 items-center py-12">
          <div>
            <h2 className="text-4xl font-extrabold leading-tight">Nature's Healing. Science's Assurance.</h2>
            <p className="mt-4 text-gray-600">Personalized Ayurvedic kits — clinically tested, ethically sourced, and built for modern life. Start with a simple 7-day ritual and feel the difference.</p>

            <div className="mt-6 flex gap-4">
              <a href="#preorder" className="bg-amber-500 hover:bg-amber-600 px-5 py-3 rounded-md text-white font-semibold">Pre-order Kit</a>
              <button onClick={() => setShowQuiz(true)} className="px-5 py-3 rounded-md border border-gray-200">Take the wellness quiz</button>
            </div>

            <div className="mt-6 flex gap-4 items-center text-sm text-gray-500">
              <div className="flex items-center gap-2"><span className="w-8 h-8 bg-green-100 text-green-700 rounded-full flex items-center justify-center">✔</span> 3rd-party lab tests</div>
              <div className="flex items-center gap-2"><span className="w-8 h-8 bg-green-100 text-green-700 rounded-full flex items-center justify-center">✔</span> Practitioner-backed</div>
            </div>
          </div>
          <div className="bg-gray-50 rounded-xl p-6">
            <img src="https://images.unsplash.com/photo-1506806732259-39c2d0268443?q=80&w=800&auto=format&fit=crop&ixlib=rb-4.0.3&s=placeholder" alt="ayurveda" className="rounded-lg w-full h-72 object-cover" />
          </div>
        </section>

        <section id="products" className="py-8">
          <h3 className="text-2xl font-bold">Starter Kits</h3>
          <p className="text-gray-600 mt-2">Choose a starter plan designed to fit into busy lives — easy rituals, powerful herbs, visible outcomes.</p>

          <div className="mt-6 grid grid-cols-1 md:grid-cols-3 gap-6">
            {products.map((p) => (
              <div key={p.id} className="border rounded-xl p-5">
                <h4 className="font-semibold">{p.title}</h4>
                <p className="text-sm text-gray-500 mt-2">{p.desc}</p>
                <div className="mt-4 flex items-center justify-between">
                  <div className="text-lg font-bold">{p.price}</div>
                  <button className="bg-green-600 text-white px-3 py-2 rounded-md text-sm">Pre-order</button>
                </div>
              </div>
            ))}
          </div>
        </section>

        <section id="how" className="py-8">
          <h3 className="text-2xl font-bold">How it works</h3>
          <ol className="mt-4 space-y-3 text-gray-600">
            <li>1. Take a 2-minute wellness quiz (or upload photos).</li>
            <li>2. Our algorithm + practitioner reviews map a personalized ritual.</li>
            <li>3. Receive a 7-day kit & simple ritual card. Subscribe when ready.</li>
          </ol>
        </section>

        <section id="preorder" className="py-8">
          <h3 className="text-2xl font-bold">Pre-order & Early Access</h3>
          <p className="text-gray-600 mt-2">Become a founding customer — limited trial kits with special pricing and free practitioner consults.</p>

          {!preorderSuccess ? (
            <form onSubmit={submitPreorder} className="mt-4 flex flex-col sm:flex-row gap-3">
              <input value={email} onChange={(e) => setEmail(e.target.value)} type="email" placeholder="Your email" className="border rounded-md px-4 py-3 flex-1" />
              <button type="submit" className="bg-amber-500 text-white px-6 py-3 rounded-md">Pre-order for ₹499</button>
            </form>
          ) : (
            <div className="mt-4 p-4 bg-green-50 rounded-md text-green-700">Thanks — we’ll email you the next steps shortly.</div>
          )}
        </section>

        <footer className="py-12 text-center text-gray-600">
          © {new Date().getFullYear()} Niramaya. All rights reserved. • Terms • Privacy
        </footer>
      </main>

      {/* Quiz Modal */}
      {showQuiz && (
        <div className="fixed inset-0 bg-black/40 flex items-center justify-center p-6">
          <div className="bg-white rounded-lg max-w-xl w-full p-6">
            <div className="flex items-center justify-between">
              <h4 className="font-bold">Wellness Quiz</h4>
              <button onClick={() => setShowQuiz(false)} className="text-gray-500">Close</button>
            </div>

            <div className="mt-4">
              {quizStep === 0 && (
                <div>
                  <p className="text-sm text-gray-600">What's your primary concern?</p>
                  <div className="mt-3 flex gap-3">
                    <button onClick={() => handleQuizAnswer('concern', 'digestion')} className="border rounded-md px-4 py-2">Digestion</button>
                    <button onClick={() => handleQuizAnswer('concern', 'stress')} className="border rounded-md px-4 py-2">Stress & Sleep</button>
                    <button onClick={() => handleQuizAnswer('concern', 'hair')} className="border rounded-md px-4 py-2">Hair & Skin</button>
                  </div>
                </div>
              )}

              {quizStep === 1 && (
                <div>
                  <p className="text-sm text-gray-600">How often do you exercise?</p>
                  <div className="mt-3 flex gap-3">
                    <button onClick={() => handleQuizAnswer('exercise', 'regular')} className="border rounded-md px-4 py-2">4+ times/week</button>
                    <button onClick={() => handleQuizAnswer('exercise', 'sometimes')} className="border rounded-md px-4 py-2">1–3 times/week</button>
                    <button onClick={() => handleQuizAnswer('exercise', 'rarely')} className="border rounded-md px-4 py-2">Rarely</button>
                  </div>
                </div>
              )}

              {quizStep === 2 && (
                <div>
                  <p className="text-sm text-gray-600">Do you prefer ingestible (tea/capsule) or topical ritual?</p>
                  <div className="mt-3 flex gap-3">
                    <button onClick={() => handleQuizAnswer('pref', 'ingestible')} className="border rounded-md px-4 py-2">Ingestible</button>
                    <button onClick={() => handleQuizAnswer('pref', 'topical')} className="border rounded-md px-4 py-2">Topical</button>
                  </div>
                </div>
              )}

              {quizStep >= 3 && (
                <div>
                  <h5 className="font-semibold">Thanks — here’s your starter recommendation</h5>
                  <p className="text-sm text-gray-600 mt-2">Based on your answers, we recommend the <strong>7-Day Reboot Kit</strong>. Would you like to pre-order at the special trial price?</p>
                  <div className="mt-4 flex gap-3">
                    <button onClick={() => { setPreorderSuccess(true); setShowQuiz(false); }} className="bg-amber-500 px-4 py-2 rounded-md text-white">Pre-order ₹499</button>
                    <button onClick={resetQuiz} className="border px-4 py-2 rounded-md">Retake</button>
                  </div>
                </div>
              )}
            </div>
          </div>
        </div>
      )}
    </div>
  );
}
