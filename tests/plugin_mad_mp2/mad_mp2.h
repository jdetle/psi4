<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  
  

  


  

  <head>
    <title>
      /trunk/tests/plugin_mad_mp2/mad_mp2.h – Psi4
    </title>
        <link rel="search" href="/trac/search" />
        <link rel="help" href="/trac/wiki/TracGuide" />
        <link rel="alternate" href="/trac/browser/trunk/tests/plugin_mad_mp2/mad_mp2.h?format=txt" type="text/plain" title="Plain Text" /><link rel="alternate" href="/trac/export/1983/trunk/tests/plugin_mad_mp2/mad_mp2.h" type="text/x-chdr; charset=iso-8859-15" title="Original Format" />
        <link rel="up" href="/trac/browser/trunk/tests/plugin_mad_mp2" title="Parent directory" />
        <link rel="start" href="/trac/wiki" />
        <link rel="stylesheet" href="/trac/chrome/common/css/trac.css" type="text/css" /><link rel="stylesheet" href="/trac/chrome/common/css/code.css" type="text/css" /><link rel="stylesheet" href="/trac/pygments/trac.css" type="text/css" /><link rel="stylesheet" href="/trac/chrome/common/css/browser.css" type="text/css" /><link rel="stylesheet" href="/trac/chrome/googlemap/tracgooglemap.css" type="text/css" />
        <link rel="google-key" href="" class="google-key" title="ABQIAAAAEm-sB5Hq7DJNrZXGU2EXlxTthLP7MnSeoBrJ-Mt6ZcDfmRQM3RTqr4vj7oIAm9RhoGjV8d0hktaebQ" />
        <link rel="shortcut icon" href="/trac/chrome/site/logo.png" type="image/png" />
        <link rel="icon" href="/trac/chrome/site/logo.png" type="image/png" />
      <link type="application/opensearchdescription+xml" rel="search" href="/trac/search/opensearch" title="Search Psi4" />
    <script type="text/javascript" src="/trac/chrome/common/js/jquery.js"></script><script type="text/javascript" src="/trac/chrome/common/js/trac.js"></script><script type="text/javascript" src="/trac/chrome/common/js/search.js"></script><script type="text/javascript" src="/trac/chrome/googlemap/tracgooglemap.js"></script>
    <!--[if lt IE 7]>
    <script type="text/javascript" src="/trac/chrome/common/js/ie_pre7_hacks.js"></script>
    <![endif]-->
    <script type="text/javascript">
      jQuery(document).ready(function($) {
        $(".trac-toggledeleted").show().click(function() {
                  $(this).siblings().find(".trac-deleted").toggle();
                  return false;
        }).click();
        $("#jumploc input").hide();
        $("#jumploc select").change(function () {
          this.parentNode.parentNode.submit();
        });
      });
    </script>
  </head>
  <body>
    <div id="banner">
      <div id="header">
        <a id="logo" href="/trac/wiki"><img src="/trac/chrome/site/PSI4_3.png" alt="Welcome to the Psi4 Trac page" height="120" width="480" /></a>
      </div>
      <form id="search" action="/trac/search" method="get">
        <div>
          <label for="proj-search">Search:</label>
          <input type="text" id="proj-search" name="q" size="18" value="" />
          <input type="submit" value="Search" />
        </div>
      </form>
      <div id="metanav" class="nav">
    <ul>
      <li class="first">logged in as rparrish6</li><li><a href="/trac/logout">Logout</a></li><li><a href="/trac/prefs">Preferences</a></li><li><a href="/trac/wiki/TracGuide">Help/Guide</a></li><li class="last"><a href="/trac/about">About Trac</a></li>
    </ul>
  </div>
    </div>
    <div id="mainnav" class="nav">
    <ul>
      <li class="first"><a href="/trac/wiki">Wiki</a></li><li><a href="/trac/timeline">Timeline</a></li><li><a href="/trac/roadmap">Roadmap</a></li><li class="active"><a href="/trac/log/trunk?rev=latest">Browse Source</a></li><li><a href="/trac/report">View Tickets</a></li><li><a href="/trac/newticket">New Ticket</a></li><li><a href="/trac/search">Search</a></li><li><a href="/trac/doxygen">Doxygen</a></li><li><a href="/trac/admin" title="Administration">Admin</a></li><li class="last"><a href="/trac/discussion">Forum</a></li>
    </ul>
  </div>
    <div id="main">
      <div id="ctxtnav" class="nav">
        <h2>Context Navigation</h2>
          <ul>
              <li class="first"><a href="/trac/changeset/1981/trunk/tests/plugin_mad_mp2/mad_mp2.h">Last Change</a></li><li><a href="/trac/browser/trunk/tests/plugin_mad_mp2/mad_mp2.h?annotate=blame&amp;rev=1981" title="Annotate each line with the last changed revision (this can be time consuming...)">Annotate</a></li><li class="last"><a href="/trac/log/trunk/tests/plugin_mad_mp2/mad_mp2.h">Revision Log</a></li>
          </ul>
        <hr />
      </div>
    <div id="content" class="browser">
      <h1>
    <a class="pathentry first" title="Go to root directory" href="/trac/browser">root</a><span class="pathentry sep">/</span><a class="pathentry" title="View trunk" href="/trac/browser/trunk">trunk</a><span class="pathentry sep">/</span><a class="pathentry" title="View tests" href="/trac/browser/trunk/tests">tests</a><span class="pathentry sep">/</span><a class="pathentry" title="View plugin_mad_mp2" href="/trac/browser/trunk/tests/plugin_mad_mp2">plugin_mad_mp2</a><span class="pathentry sep">/</span><a class="pathentry" title="View mad_mp2.h" href="/trac/browser/trunk/tests/plugin_mad_mp2/mad_mp2.h">mad_mp2.h</a>
    <br style="clear: both" />
  </h1>
      <div id="jumprev">
        <form action="" method="get">
          <div>
            <label for="rev">
              View revision:</label>
            <input type="text" id="rev" name="rev" size="6" />
          </div>
        </form>
      </div>
      <div id="jumploc">
        <form action="" method="get">
          <div class="buttons">
            <label for="preselected">Visit:</label>
            <select id="preselected" name="preselected">
              <option selected="selected"></option>
              <optgroup label="branches">
                <option value="/trac/browser/trunk">trunk</option><option value="/trac/browser/branches/madpsi4">branches/madpsi4</option><option value="/trac/browser/branches/psi4-alpha-0">branches/psi4-alpha-0</option>
              </optgroup>
            </select>
            <input type="submit" value="Go!" title="Jump to the chosen preselected path" />
          </div>
        </form>
      </div>
      <table id="info" summary="Revision info">
        <tr>
          <th scope="col">
            Revision <a href="/trac/changeset/1981">1981</a>, <span title="5198 bytes">5.1 KB</span>
            (checked in by bmintz, <a class="timeline" href="/trac/timeline?from=2011-07-12T10%3A19%3A50-0400&amp;precision=second" title="2011-07-12T10:19:50-0400 in Timeline">35 minutes</a> ago)
          </th>
        </tr>
        <tr>
          <td class="message searchable">
              <p>
changes made to mad_mp2<br />
</p>
          </td>
        </tr>
      </table>
      <div id="preview" class="searchable">
    <table class="code"><thead><tr><th class="lineno" title="Line numbers">Line</th><th class="content"> </th></tr></thead><tbody><tr><th id="L1"><a href="#L1">1</a></th><td><span class="cp">#ifndef MAD_MP2_PROC_H</span></td></tr><tr><th id="L2"><a href="#L2">2</a></th><td><span class="cp">#define MAD_MP2_PROC_H</span></td></tr><tr><th id="L3"><a href="#L3">3</a></th><td><span class="cp"></span></td></tr><tr><th id="L4"><a href="#L4">4</a></th><td><span class="cp">#include &lt;boost/tuple/tuple.hpp&gt;</span></td></tr><tr><th id="L5"><a href="#L5">5</a></th><td><span class="cp">#include &lt;boost/tuple/tuple_comparison.hpp&gt;</span></td></tr><tr><th id="L6"><a href="#L6">6</a></th><td><span class="cp">#include &lt;libparallel/parallel.h&gt;</span></td></tr><tr><th id="L7"><a href="#L7">7</a></th><td><span class="cp">#include &lt;map&gt;</span></td></tr><tr><th id="L8"><a href="#L8">8</a></th><td><span class="cp"></span></td></tr><tr><th id="L9"><a href="#L9">9</a></th><td>namespace boost <span class="p">{</span></td></tr><tr><th id="L10"><a href="#L10">10</a></th><td>template<span class="o">&lt;</span>class T<span class="o">&gt;</span> class shared_ptr<span class="p">;</span></td></tr><tr><th id="L11"><a href="#L11">11</a></th><td><span class="p">}</span></td></tr><tr><th id="L12"><a href="#L12">12</a></th><td></td></tr><tr><th id="L13"><a href="#L13">13</a></th><td>namespace psi <span class="p">{</span></td></tr><tr><th id="L14"><a href="#L14">14</a></th><td></td></tr><tr><th id="L15"><a href="#L15">15</a></th><td>class Denominator<span class="p">;</span></td></tr><tr><th id="L16"><a href="#L16">16</a></th><td>class Matrix<span class="p">;</span> </td></tr><tr><th id="L17"><a href="#L17">17</a></th><td>class Vector<span class="p">;</span> </td></tr><tr><th id="L18"><a href="#L18">18</a></th><td>class IntVector<span class="p">;</span> </td></tr><tr><th id="L19"><a href="#L19">19</a></th><td>class BasisSet<span class="p">;</span> </td></tr><tr><th id="L20"><a href="#L20">20</a></th><td>class Wavefunction<span class="p">;</span></td></tr><tr><th id="L21"><a href="#L21">21</a></th><td>class Options<span class="p">;</span></td></tr><tr><th id="L22"><a href="#L22">22</a></th><td>class PSIO<span class="p">;</span></td></tr><tr><th id="L23"><a href="#L23">23</a></th><td>class Chkpt<span class="p">;</span></td></tr><tr><th id="L24"><a href="#L24">24</a></th><td></td></tr><tr><th id="L25"><a href="#L25">25</a></th><td>namespace  mad_mp2 <span class="p">{</span></td></tr><tr><th id="L26"><a href="#L26">26</a></th><td></td></tr><tr><th id="L27"><a href="#L27">27</a></th><td>class MAD_MP2 <span class="o">:</span> public Wavefunction <span class="p">,</span> public madness<span class="o">::</span>WorldObject<span class="o">&lt;</span>MAD_MP2<span class="o">&gt;</span></td></tr><tr><th id="L28"><a href="#L28">28</a></th><td><span class="p">{</span></td></tr><tr><th id="L29"><a href="#L29">29</a></th><td></td></tr><tr><th id="L30"><a href="#L30">30</a></th><td><span class="nl">protected:</span></td></tr><tr><th id="L31"><a href="#L31">31</a></th><td></td></tr><tr><th id="L32"><a href="#L32">32</a></th><td>    <span class="c1">// =&gt; Parallel Variables &lt;= //</span></td></tr><tr><th id="L33"><a href="#L33">33</a></th><td><span class="c1"></span>  </td></tr><tr><th id="L34"><a href="#L34">34</a></th><td>    <span class="c1">// Number of processors</span></td></tr><tr><th id="L35"><a href="#L35">35</a></th><td><span class="c1"></span>    <span class="kt">int</span> nproc_<span class="p">;</span></td></tr><tr><th id="L36"><a href="#L36">36</a></th><td>    <span class="c1">// Number of threads</span></td></tr><tr><th id="L37"><a href="#L37">37</a></th><td><span class="c1"></span>    <span class="kt">int</span> mad_nthread_<span class="p">;</span></td></tr><tr><th id="L38"><a href="#L38">38</a></th><td>    <span class="c1">// My rank</span></td></tr><tr><th id="L39"><a href="#L39">39</a></th><td><span class="c1"></span>    <span class="kt">int</span> rank_<span class="p">;</span>  </td></tr><tr><th id="L40"><a href="#L40">40</a></th><td>    <span class="c1">// Communicator Type</span></td></tr><tr><th id="L41"><a href="#L41">41</a></th><td><span class="c1"></span>    std<span class="o">::</span>string comm_<span class="p">;</span>  </td></tr><tr><th id="L42"><a href="#L42">42</a></th><td>    <span class="c1">// Total number of ia pairs    </span></td></tr><tr><th id="L43"><a href="#L43">43</a></th><td><span class="c1"></span>    ULI nia_<span class="p">;</span></td></tr><tr><th id="L44"><a href="#L44">44</a></th><td>    <span class="c1">// Local number of ia pairs</span></td></tr><tr><th id="L45"><a href="#L45">45</a></th><td><span class="c1"></span>    ULI nia_local_<span class="p">;</span></td></tr><tr><th id="L46"><a href="#L46">46</a></th><td>    <span class="c1">// ia pair assignments</span></td></tr><tr><th id="L47"><a href="#L47">47</a></th><td><span class="c1"></span>    std<span class="o">::</span>vector<span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> ia_owner_<span class="p">;</span></td></tr><tr><th id="L48"><a href="#L48">48</a></th><td>    <span class="c1">// ablock owner for given i</span></td></tr><tr><th id="L49"><a href="#L49">49</a></th><td><span class="c1"></span>    std<span class="o">::</span>vector<span class="o">&lt;</span>std<span class="o">::</span>vector<span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="o">&gt;</span> ablock_owner_<span class="p">;</span></td></tr><tr><th id="L50"><a href="#L50">50</a></th><td>    <span class="c1">// global a ablock starts for given i</span></td></tr><tr><th id="L51"><a href="#L51">51</a></th><td><span class="c1"></span>    std<span class="o">::</span>vector<span class="o">&lt;</span>std<span class="o">::</span>vector<span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="o">&gt;</span> ablock_start_<span class="p">;</span></td></tr><tr><th id="L52"><a href="#L52">52</a></th><td>    <span class="c1">// global a ablock sizes for given i</span></td></tr><tr><th id="L53"><a href="#L53">53</a></th><td><span class="c1"></span>    std<span class="o">::</span>vector<span class="o">&lt;</span>std<span class="o">::</span>vector<span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> <span class="o">&gt;</span> ablock_size_<span class="p">;</span></td></tr><tr><th id="L54"><a href="#L54">54</a></th><td>    <span class="c1">// Local ia pair assignments</span></td></tr><tr><th id="L55"><a href="#L55">55</a></th><td><span class="c1"></span>    std<span class="o">::</span>vector<span class="o">&lt;</span>ULI<span class="o">&gt;</span> ia_local_to_global_<span class="p">;</span></td></tr><tr><th id="L56"><a href="#L56">56</a></th><td>    <span class="c1">// Global ia pair assignments  </span></td></tr><tr><th id="L57"><a href="#L57">57</a></th><td><span class="c1"></span>    std<span class="o">::</span>map<span class="o">&lt;</span>ULI<span class="p">,</span> <span class="kt">int</span><span class="o">&gt;</span> ia_global_to_local_<span class="p">;</span></td></tr><tr><th id="L58"><a href="#L58">58</a></th><td>    <span class="c1">// Global i assignments</span></td></tr><tr><th id="L59"><a href="#L59">59</a></th><td><span class="c1"></span>    std<span class="o">::</span>map<span class="o">&lt;</span><span class="kt">int</span><span class="p">,</span><span class="kt">int</span><span class="o">&gt;</span> i_global_to_local_<span class="p">;</span></td></tr><tr><th id="L60"><a href="#L60">60</a></th><td>    <span class="c1">// Local number of i</span></td></tr><tr><th id="L61"><a href="#L61">61</a></th><td><span class="c1"></span>    <span class="kt">int</span> naocc_local_<span class="p">;</span></td></tr><tr><th id="L62"><a href="#L62">62</a></th><td>    <span class="c1">// Local number of a</span></td></tr><tr><th id="L63"><a href="#L63">63</a></th><td><span class="c1"></span>    <span class="kt">int</span> navir_local_<span class="p">;</span></td></tr><tr><th id="L64"><a href="#L64">64</a></th><td>    <span class="c1">// Local i values</span></td></tr><tr><th id="L65"><a href="#L65">65</a></th><td><span class="c1"></span>    std<span class="o">::</span>vector<span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> aocc_local_<span class="p">;</span></td></tr><tr><th id="L66"><a href="#L66">66</a></th><td>    <span class="c1">// Local a values</span></td></tr><tr><th id="L67"><a href="#L67">67</a></th><td><span class="c1"></span>    std<span class="o">::</span>vector<span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span> avir_local_<span class="p">;</span></td></tr><tr><th id="L68"><a href="#L68">68</a></th><td></td></tr><tr><th id="L69"><a href="#L69">69</a></th><td>    <span class="c1">/// Energies table</span></td></tr><tr><th id="L70"><a href="#L70">70</a></th><td><span class="c1"></span>    std<span class="o">::</span>map<span class="o">&lt;</span>std<span class="o">::</span>string<span class="p">,</span> <span class="kt">double</span><span class="o">&gt;</span> energies_<span class="p">;</span></td></tr><tr><th id="L71"><a href="#L71">71</a></th><td></td></tr><tr><th id="L72"><a href="#L72">72</a></th><td>    <span class="c1">/// Total MP2J terms</span></td></tr><tr><th id="L73"><a href="#L73">73</a></th><td><span class="c1"></span>    <span class="kt">double</span> E_MP2J_<span class="p">;</span></td></tr><tr><th id="L74"><a href="#L74">74</a></th><td>    <span class="c1">/// Total MP2K terms</span></td></tr><tr><th id="L75"><a href="#L75">75</a></th><td><span class="c1"></span>    <span class="kt">double</span> E_MP2K_<span class="p">;</span></td></tr><tr><th id="L76"><a href="#L76">76</a></th><td></td></tr><tr><th id="L77"><a href="#L77">77</a></th><td>    <span class="c1">/// Same-spin scale</span></td></tr><tr><th id="L78"><a href="#L78">78</a></th><td><span class="c1"></span>    <span class="kt">double</span> scale_ss_<span class="p">;</span></td></tr><tr><th id="L79"><a href="#L79">79</a></th><td>    <span class="c1">/// Opposite-spin scale</span></td></tr><tr><th id="L80"><a href="#L80">80</a></th><td><span class="c1"></span>    <span class="kt">double</span> scale_os_<span class="p">;</span></td></tr><tr><th id="L81"><a href="#L81">81</a></th><td>    </td></tr><tr><th id="L82"><a href="#L82">82</a></th><td>    <span class="c1">/// Print flag</span></td></tr><tr><th id="L83"><a href="#L83">83</a></th><td><span class="c1"></span>    <span class="kt">int</span> print_<span class="p">;</span></td></tr><tr><th id="L84"><a href="#L84">84</a></th><td>    <span class="c1">/// Debug flag</span></td></tr><tr><th id="L85"><a href="#L85">85</a></th><td><span class="c1"></span>    <span class="kt">int</span> debug_<span class="p">;</span>   </td></tr><tr><th id="L86"><a href="#L86">86</a></th><td>    <span class="c1">/// Number of OMP threads</span></td></tr><tr><th id="L87"><a href="#L87">87</a></th><td><span class="c1"></span>    <span class="kt">int</span> omp_nthread_<span class="p">;</span></td></tr><tr><th id="L88"><a href="#L88">88</a></th><td></td></tr><tr><th id="L89"><a href="#L89">89</a></th><td>    <span class="c1">/// Size of auxiliary basis set</span></td></tr><tr><th id="L90"><a href="#L90">90</a></th><td><span class="c1"></span>    <span class="kt">int</span> naux_<span class="p">;</span></td></tr><tr><th id="L91"><a href="#L91">91</a></th><td>    <span class="c1">/// Auxiliary basis set</span></td></tr><tr><th id="L92"><a href="#L92">92</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>BasisSet<span class="o">&gt;</span> auxiliary_<span class="p">;</span></td></tr><tr><th id="L93"><a href="#L93">93</a></th><td>    <span class="c1">/// Zero basis set</span></td></tr><tr><th id="L94"><a href="#L94">94</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>BasisSet<span class="o">&gt;</span> zero_<span class="p">;</span>    </td></tr><tr><th id="L95"><a href="#L95">95</a></th><td>    <span class="c1">/// Auxiliary basis automagical?</span></td></tr><tr><th id="L96"><a href="#L96">96</a></th><td><span class="c1"></span>    bool auxiliary_automatic_<span class="p">;</span></td></tr><tr><th id="L97"><a href="#L97">97</a></th><td></td></tr><tr><th id="L98"><a href="#L98">98</a></th><td>    <span class="c1">/// Reference wavefunction pointer</span></td></tr><tr><th id="L99"><a href="#L99">99</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>Wavefunction<span class="o">&gt;</span> reference_<span class="p">;</span></td></tr><tr><th id="L100"><a href="#L100">100</a></th><td>    <span class="c1">/// SCF energy</span></td></tr><tr><th id="L101"><a href="#L101">101</a></th><td><span class="c1"></span>    <span class="kt">double</span> Eref_<span class="p">;</span></td></tr><tr><th id="L102"><a href="#L102">102</a></th><td></td></tr><tr><th id="L103"><a href="#L103">103</a></th><td>    <span class="c1">// =&gt; Orbital sizing/data &lt;= //</span></td></tr><tr><th id="L104"><a href="#L104">104</a></th><td><span class="c1"></span></td></tr><tr><th id="L105"><a href="#L105">105</a></th><td>    <span class="c1">/// Total number of frozen occupied orbitals</span></td></tr><tr><th id="L106"><a href="#L106">106</a></th><td><span class="c1"></span>    <span class="kt">int</span> nfocc_<span class="p">;</span></td></tr><tr><th id="L107"><a href="#L107">107</a></th><td>    <span class="c1">/// Total number of active occupied orbitals</span></td></tr><tr><th id="L108"><a href="#L108">108</a></th><td><span class="c1"></span>    <span class="kt">int</span> naocc_<span class="p">;</span>    </td></tr><tr><th id="L109"><a href="#L109">109</a></th><td>    <span class="c1">/// Total number of active virtual orbitals</span></td></tr><tr><th id="L110"><a href="#L110">110</a></th><td><span class="c1"></span>    <span class="kt">int</span> navir_<span class="p">;</span>    </td></tr><tr><th id="L111"><a href="#L111">111</a></th><td>    <span class="c1">/// Total number of frozen virtual orbitals</span></td></tr><tr><th id="L112"><a href="#L112">112</a></th><td><span class="c1"></span>    <span class="kt">int</span> nfvir_<span class="p">;</span></td></tr><tr><th id="L113"><a href="#L113">113</a></th><td></td></tr><tr><th id="L114"><a href="#L114">114</a></th><td>    <span class="c1">/// Number of active occupieds per irrep</span></td></tr><tr><th id="L115"><a href="#L115">115</a></th><td><span class="c1"></span>    <span class="kt">int</span> naoccpi_<span class="p">[</span><span class="mi">8</span><span class="p">];</span></td></tr><tr><th id="L116"><a href="#L116">116</a></th><td>    <span class="c1">/// Number of active virtuals per irrep</span></td></tr><tr><th id="L117"><a href="#L117">117</a></th><td><span class="c1"></span>    <span class="kt">int</span> navirpi_<span class="p">[</span><span class="mi">8</span><span class="p">];</span></td></tr><tr><th id="L118"><a href="#L118">118</a></th><td>    <span class="c1">/// Cumsum of naoccpi_</span></td></tr><tr><th id="L119"><a href="#L119">119</a></th><td><span class="c1"></span>    <span class="kt">int</span> offset_aocc_<span class="p">[</span><span class="mi">8</span><span class="p">];</span>   </td></tr><tr><th id="L120"><a href="#L120">120</a></th><td>    <span class="c1">/// Cumsum of navirpi_</span></td></tr><tr><th id="L121"><a href="#L121">121</a></th><td><span class="c1"></span>    <span class="kt">int</span> offset_avir_<span class="p">[</span><span class="mi">8</span><span class="p">];</span>   </td></tr><tr><th id="L122"><a href="#L122">122</a></th><td> </td></tr><tr><th id="L123"><a href="#L123">123</a></th><td>    <span class="c1">/// AO2USO transform matrix</span></td></tr><tr><th id="L124"><a href="#L124">124</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>Matrix<span class="o">&gt;</span> AO2USO_<span class="p">;</span> </td></tr><tr><th id="L125"><a href="#L125">125</a></th><td>    <span class="c1">/// AO2USO transform matrix (auxiliary)</span></td></tr><tr><th id="L126"><a href="#L126">126</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>Matrix<span class="o">&gt;</span> AO2USO_aux_<span class="p">;</span> </td></tr><tr><th id="L127"><a href="#L127">127</a></th><td>    <span class="c1">/// SOs per irrep in the auxiliary basis</span></td></tr><tr><th id="L128"><a href="#L128">128</a></th><td><span class="c1"></span>    <span class="kt">int</span> nauxpi_<span class="p">[</span><span class="mi">8</span><span class="p">];</span></td></tr><tr><th id="L129"><a href="#L129">129</a></th><td>   </td></tr><tr><th id="L130"><a href="#L130">130</a></th><td>    <span class="c1">/// Max active occupieds per irrep</span></td></tr><tr><th id="L131"><a href="#L131">131</a></th><td><span class="c1"></span>    <span class="kt">int</span> max_naoccpi_<span class="p">;</span></td></tr><tr><th id="L132"><a href="#L132">132</a></th><td>    <span class="c1">/// Max active occupieds per irrep</span></td></tr><tr><th id="L133"><a href="#L133">133</a></th><td><span class="c1"></span>    <span class="kt">int</span> max_navirpi_<span class="p">;</span></td></tr><tr><th id="L134"><a href="#L134">134</a></th><td>    <span class="c1">/// Max active occupieds per irrep</span></td></tr><tr><th id="L135"><a href="#L135">135</a></th><td><span class="c1"></span>    <span class="kt">int</span> max_nauxpi_<span class="p">;</span></td></tr><tr><th id="L136"><a href="#L136">136</a></th><td> </td></tr><tr><th id="L137"><a href="#L137">137</a></th><td>    <span class="c1">/// C1 copy of active occupied orbitals</span></td></tr><tr><th id="L138"><a href="#L138">138</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>Matrix<span class="o">&gt;</span> Caocc_<span class="p">;</span></td></tr><tr><th id="L139"><a href="#L139">139</a></th><td>    <span class="c1">/// C1 copy of active virtual orbitals </span></td></tr><tr><th id="L140"><a href="#L140">140</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>Matrix<span class="o">&gt;</span> Cavir_<span class="p">;</span></td></tr><tr><th id="L141"><a href="#L141">141</a></th><td>    </td></tr><tr><th id="L142"><a href="#L142">142</a></th><td>    <span class="c1">/// C1 copy of active occupied evals</span></td></tr><tr><th id="L143"><a href="#L143">143</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>Vector<span class="o">&gt;</span> eps_aocc_<span class="p">;</span></td></tr><tr><th id="L144"><a href="#L144">144</a></th><td>    <span class="c1">/// C1 copy of active virtual evals</span></td></tr><tr><th id="L145"><a href="#L145">145</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>Vector<span class="o">&gt;</span> eps_avir_<span class="p">;</span></td></tr><tr><th id="L146"><a href="#L146">146</a></th><td></td></tr><tr><th id="L147"><a href="#L147">147</a></th><td>    <span class="c1">/// C1 copy of active occupied irreps</span></td></tr><tr><th id="L148"><a href="#L148">148</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>IntVector<span class="o">&gt;</span> irrep_aocc_<span class="p">;</span></td></tr><tr><th id="L149"><a href="#L149">149</a></th><td>    <span class="c1">/// C1 copy of active virtual irreps</span></td></tr><tr><th id="L150"><a href="#L150">150</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>IntVector<span class="o">&gt;</span> irrep_avir_<span class="p">;</span></td></tr><tr><th id="L151"><a href="#L151">151</a></th><td></td></tr><tr><th id="L152"><a href="#L152">152</a></th><td>    <span class="c1">// =&gt; Key Tensors &lt;= //</span></td></tr><tr><th id="L153"><a href="#L153">153</a></th><td><span class="c1"></span></td></tr><tr><th id="L154"><a href="#L154">154</a></th><td>    <span class="c1">/// J^-1/2</span></td></tr><tr><th id="L155"><a href="#L155">155</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>Matrix<span class="o">&gt;</span> Jm12_<span class="p">;</span></td></tr><tr><th id="L156"><a href="#L156">156</a></th><td>    <span class="c1">/// (A|ia) </span></td></tr><tr><th id="L157"><a href="#L157">157</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>Matrix<span class="o">&gt;</span> Aia_<span class="p">;</span> </td></tr><tr><th id="L158"><a href="#L158">158</a></th><td>    <span class="c1">/// \tau_ia^Q</span></td></tr><tr><th id="L159"><a href="#L159">159</a></th><td><span class="c1"></span>    boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>Denominator<span class="o">&gt;</span> denom_<span class="p">;</span>    </td></tr><tr><th id="L160"><a href="#L160">160</a></th><td> </td></tr><tr><th id="L161"><a href="#L161">161</a></th><td>    <span class="c1">// =&gt; Compute routines &lt;= //</span></td></tr><tr><th id="L162"><a href="#L162">162</a></th><td><span class="c1"></span></td></tr><tr><th id="L163"><a href="#L163">163</a></th><td>    <span class="c1">/// Handle sizing, orbital evals, and C matrix</span></td></tr><tr><th id="L164"><a href="#L164">164</a></th><td><span class="c1"></span>    <span class="k">virtual</span> <span class="kt">void</span> common_init<span class="p">();</span></td></tr><tr><th id="L165"><a href="#L165">165</a></th><td>    <span class="c1">/// Handle parallel initialization/sizing</span></td></tr><tr><th id="L166"><a href="#L166">166</a></th><td><span class="c1"></span>    <span class="k">virtual</span> <span class="kt">void</span> parallel_init<span class="p">();</span></td></tr><tr><th id="L167"><a href="#L167">167</a></th><td>    <span class="c1">/// Print the header</span></td></tr><tr><th id="L168"><a href="#L168">168</a></th><td><span class="c1"></span>    <span class="k">virtual</span> <span class="kt">void</span> print_header<span class="p">();</span></td></tr><tr><th id="L169"><a href="#L169">169</a></th><td>    <span class="c1">/// Build the MP2J Cholesky or Laplace denominator</span></td></tr><tr><th id="L170"><a href="#L170">170</a></th><td><span class="c1"></span>    <span class="k">virtual</span> <span class="kt">void</span> denominator<span class="p">();</span></td></tr><tr><th id="L171"><a href="#L171">171</a></th><td>    <span class="c1">/// Detemine memory, and striping information</span></td></tr><tr><th id="L172"><a href="#L172">172</a></th><td><span class="c1"></span>    <span class="k">virtual</span> <span class="kt">void</span> check_memory<span class="p">();</span></td></tr><tr><th id="L173"><a href="#L173">173</a></th><td>    <span class="c1">/// Build J </span></td></tr><tr><th id="L174"><a href="#L174">174</a></th><td><span class="c1"></span>    <span class="k">virtual</span> <span class="kt">void</span> J<span class="p">();</span></td></tr><tr><th id="L175"><a href="#L175">175</a></th><td>    <span class="c1">/// Build J^-1/2 </span></td></tr><tr><th id="L176"><a href="#L176">176</a></th><td><span class="c1"></span>    <span class="k">virtual</span> <span class="kt">void</span> Jm12<span class="p">();</span></td></tr><tr><th id="L177"><a href="#L177">177</a></th><td>    <span class="c1">/// Build Aia, Ami, Amn on the go</span></td></tr><tr><th id="L178"><a href="#L178">178</a></th><td><span class="c1"></span>    <span class="k">virtual</span> <span class="kt">void</span> Aia<span class="p">();</span></td></tr><tr><th id="L179"><a href="#L179">179</a></th><td>    <span class="c1">/// Build I, find contributions to energy</span></td></tr><tr><th id="L180"><a href="#L180">180</a></th><td><span class="c1"></span>    <span class="k">virtual</span> <span class="kt">void</span> I<span class="p">();</span></td></tr><tr><th id="L181"><a href="#L181">181</a></th><td>    <span class="c1">/// Build I_MP2J, find contributions to energy</span></td></tr><tr><th id="L182"><a href="#L182">182</a></th><td><span class="c1"></span>    <span class="k">virtual</span> <span class="kt">void</span> IJ<span class="p">();</span></td></tr><tr><th id="L183"><a href="#L183">183</a></th><td>    <span class="c1">/// Print the energies</span></td></tr><tr><th id="L184"><a href="#L184">184</a></th><td><span class="c1"></span>    <span class="kt">void</span> print_energy<span class="p">();</span></td></tr><tr><th id="L185"><a href="#L185">185</a></th><td></td></tr><tr><th id="L186"><a href="#L186">186</a></th><td>    madness<span class="o">::</span>Future<span class="o">&lt;</span>std<span class="o">::</span>vector<span class="o">&lt;</span><span class="kt">double</span><span class="o">&gt;</span> <span class="o">&gt;</span> fetch_Qia_block<span class="p">(</span><span class="k">const</span> <span class="kt">int</span><span class="o">&amp;</span> i<span class="p">,</span> <span class="k">const</span> <span class="kt">int</span><span class="o">&amp;</span> ablock<span class="p">);</span></td></tr><tr><th id="L187"><a href="#L187">187</a></th><td>    madness<span class="o">::</span>Void unpack_Qia_block<span class="p">(</span><span class="k">const</span> std<span class="o">::</span>vector<span class="o">&lt;</span><span class="kt">double</span><span class="o">&gt;&amp;</span> block<span class="p">,</span> SharedMatrix Q<span class="p">,</span> <span class="k">const</span> <span class="kt">int</span><span class="o">&amp;</span> astart<span class="p">,</span> <span class="k">const</span> <span class="kt">int</span><span class="o">&amp;</span> asize<span class="p">);</span></td></tr><tr><th id="L188"><a href="#L188">188</a></th><td></td></tr><tr><th id="L189"><a href="#L189">189</a></th><td><span class="nl">public:</span></td></tr><tr><th id="L190"><a href="#L190">190</a></th><td>    MAD_MP2<span class="p">(</span>Options<span class="o">&amp;</span> options<span class="p">,</span> boost<span class="o">::</span>shared_ptr<span class="o">&lt;</span>PSIO<span class="o">&gt;</span> psio<span class="p">);</span></td></tr><tr><th id="L191"><a href="#L191">191</a></th><td>    <span class="k">virtual</span> <span class="o">~</span>MAD_MP2<span class="p">();</span></td></tr><tr><th id="L192"><a href="#L192">192</a></th><td></td></tr><tr><th id="L193"><a href="#L193">193</a></th><td>    <span class="c1">/// Pure virtual from Wavefunction</span></td></tr><tr><th id="L194"><a href="#L194">194</a></th><td><span class="c1"></span>    <span class="k">virtual</span> <span class="kt">double</span> compute_energy<span class="p">();</span></td></tr><tr><th id="L195"><a href="#L195">195</a></th><td></td></tr><tr><th id="L196"><a href="#L196">196</a></th><td><span class="p">};</span></td></tr><tr><th id="L197"><a href="#L197">197</a></th><td></td></tr><tr><th id="L198"><a href="#L198">198</a></th><td><span class="p">}}</span> <span class="c1">// Namespaces</span></td></tr><tr><th id="L199"><a href="#L199">199</a></th><td><span class="c1"></span><span class="cp"></span></td></tr><tr><th id="L200"><a href="#L200">200</a></th><td><span class="cp">#endif</span></td></tr><tr><th id="L201"><a href="#L201">201</a></th><td><span class="cp"></span></td></tr></tbody></table>
      </div>
      <div id="help">
        <strong>Note:</strong> See <a href="/trac/wiki/TracBrowser">TracBrowser</a>
        for help on using the browser.
      </div>
      <div id="anydiff">
        <form action="/trac/diff" method="get">
          <div class="buttons">
            <input type="hidden" name="new_path" value="/trunk/tests/plugin_mad_mp2/mad_mp2.h" />
            <input type="hidden" name="old_path" value="/trunk/tests/plugin_mad_mp2/mad_mp2.h" />
            <input type="hidden" name="new_rev" />
            <input type="hidden" name="old_rev" />
            <input type="submit" value="View changes..." title="Select paths and revs for Diff" />
          </div>
        </form>
      </div>
    </div>
    <div id="altlinks">
      <h3>Download in other formats:</h3>
      <ul>
        <li class="first">
          <a rel="nofollow" href="/trac/browser/trunk/tests/plugin_mad_mp2/mad_mp2.h?format=txt">Plain Text</a>
        </li><li class="last">
          <a rel="nofollow" href="/trac/export/1983/trunk/tests/plugin_mad_mp2/mad_mp2.h">Original Format</a>
        </li>
      </ul>
    </div>
    </div>
    <div id="footer" lang="en" xml:lang="en"><hr />
      <a id="tracpowered" href="http://trac.edgewall.org/"><img src="/trac/chrome/common/trac_logo_mini.png" height="30" width="107" alt="Trac Powered" /></a>
      <p class="left">
        Powered by <a href="/trac/about"><strong>Trac 0.11.7</strong></a><br />
        By <a href="http://www.edgewall.org/">Edgewall Software</a>.
      </p>
      <p class="right">www.psicode.org - The home of Psi4 on the internet.</p>
    </div>
  </body>
</html>